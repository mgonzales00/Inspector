#include "mainwindow.h"
#include "./ui_mainwindow.h"

void MainWindow::Debug(QString title, QString text)
{
    QMessageBox msgBox;

    msgBox.setWindowTitle(title);
    msgBox.setText(text);
    msgBox.exec();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpenFile_triggered()
{
    // Create file dialog box
    fileName = QFileDialog::getOpenFileName(this, "Open a file", QDir::currentPath(), "Executables (*.exe)");
    QFileInfo fileInfo(fileName);
    setWindowTitle("File: " + fileInfo.fileName());
}

void MainWindow::on_pushButton_clicked()
{
    if (fileName.isEmpty())
    {
        Debug("Error", "Please select a file.");
        return;
    }

    // Open file
    HANDLE file = CreateFileW(fileName.toStdWString().c_str(), GENERIC_ALL, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file == INVALID_HANDLE_VALUE)
    {
        Debug("Error", fileName);
        return;
    }

    // Allocate space on heap to load PE
    DWORD fileSize = GetFileSize(file, nullptr);
    LPVOID fileData = HeapAlloc(GetProcessHeap(), 0, fileSize);

    DWORD bytesRead;

    bool readFileStatus = ReadFile(file, fileData, fileSize, &bytesRead, nullptr);
    if (!readFileStatus || bytesRead != fileSize)
    {
        Debug("Error", "Failed to read entire file.");
        HeapFree(GetProcessHeap(), 0, fileData);
        CloseHandle(file);
        return;
    }

    // Detect architecture
    DWORD arch = 0;
    GetBinaryTypeW(fileName.toStdWString().c_str(), &arch);

    switch(arch)
    {
    case SCS_32BIT_BINARY:
        architecture = "x86 (32-bit)";
        Debug("Alert", "This is a 32-bit executable.");
        ParseImage32(fileData);
        break;
    case SCS_64BIT_BINARY:
        architecture = "x86-64 (64-bit)";
        Debug("Alert", "This is a 64-bit executable.");
        ParseImage64(fileData);
        break;
    default:
        Debug("Error", "Invalid architecture.");
    }

    // Cleanup
    HeapFree(GetProcessHeap(), 0, fileData);
    CloseHandle(file);
}

// 32-bit images
void MainWindow::ParseImage32(LPVOID imageBase)
{
    // Grab DOS header from within image
    PIMAGE_DOS_HEADER imageDOSHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(imageBase);

    // Grab NT header
    PIMAGE_NT_HEADERS imageNTHeader = reinterpret_cast<PIMAGE_NT_HEADERS>(reinterpret_cast<DWORD_PTR>(imageDOSHeader) + imageDOSHeader->e_lfanew); // e_lfanew is the offset in bytes from the beginning of the DOS header to the NT headers

    // Grab file header
    IMAGE_FILE_HEADER imageFileHeader = imageNTHeader->FileHeader;

    // Grab optional header
    IMAGE_OPTIONAL_HEADER imageOptionalHeader = imageNTHeader->OptionalHeader;

    // Grab section header
    PIMAGE_SECTION_HEADER imageSectionHeader = reinterpret_cast<PIMAGE_SECTION_HEADER>(reinterpret_cast<DWORD_PTR>(imageNTHeader) + 0x04 + sizeof(IMAGE_FILE_HEADER) + imageFileHeader.SizeOfOptionalHeader); // +0x04 to skip NT signature

    // IMAGE_DOS_HEADER
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(QString("0x%1").arg(imageDOSHeader->e_magic, 0, 16)));
    ui->tableWidget->setItem(1, 0, new QTableWidgetItem(QString("0x%1").arg(imageDOSHeader->e_cblp, 0, 16)));
    ui->tableWidget->setItem(2, 0, new QTableWidgetItem(QString("0x%1").arg(imageDOSHeader->e_cp, 0, 16)));
    ui->tableWidget->setItem(3, 0, new QTableWidgetItem(QString("0x%1").arg(imageDOSHeader->e_crlc, 0, 16)));
    ui->tableWidget->setItem(4, 0, new QTableWidgetItem(QString("0x%1").arg(imageDOSHeader->e_cparhdr, 0, 16)));
    ui->tableWidget->setItem(5, 0, new QTableWidgetItem(QString("0x%1").arg(imageDOSHeader->e_minalloc, 0, 16)));
    ui->tableWidget->setItem(6, 0, new QTableWidgetItem(QString("0x%1").arg(imageDOSHeader->e_maxalloc, 0, 16)));
    ui->tableWidget->setItem(7, 0, new QTableWidgetItem(QString("0x%1").arg(imageDOSHeader->e_ss, 0, 16)));
    ui->tableWidget->setItem(8, 0, new QTableWidgetItem(QString("0x%1").arg(imageDOSHeader->e_sp, 0, 16)));
    ui->tableWidget->setItem(9, 0, new QTableWidgetItem(QString("0x%1").arg(imageDOSHeader->e_csum, 0, 16)));
    ui->tableWidget->setItem(10, 0, new QTableWidgetItem(QString("0x%1").arg(imageDOSHeader->e_ip, 0, 16)));
    ui->tableWidget->setItem(11, 0, new QTableWidgetItem(QString("0x%1").arg(imageDOSHeader->e_cs, 0, 16)));
    ui->tableWidget->setItem(12, 0, new QTableWidgetItem(QString("0x%1").arg(imageDOSHeader->e_lfarlc, 0, 16)));
    ui->tableWidget->setItem(13, 0, new QTableWidgetItem(QString("0x%1").arg(imageDOSHeader->e_ovno, 0, 16)));
    ui->tableWidget->setItem(14, 0, new QTableWidgetItem(QString("0x%1").arg(imageDOSHeader->e_oemid, 0, 16)));
    ui->tableWidget->setItem(15, 0, new QTableWidgetItem(QString("0x%1").arg(imageDOSHeader->e_oeminfo, 0, 16)));
    ui->tableWidget->setItem(16, 0, new QTableWidgetItem(QString("0x%1").arg(imageDOSHeader->e_lfanew, 0, 16)));

    // IMAGE_NT_HEADERS

    // FILE_HEADER

    // OPTIONAL_HEADER

    // DATA_DIRECTORIES

    // SECTION_HEADERS

    // Get offset to first section header

    // Get offset to the import directory RVA
}

// 64-bit images
void MainWindow::ParseImage64(LPVOID imageBase)
{
    // Grab DOS header from within image
    PIMAGE_DOS_HEADER imageDOSHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(imageBase);

    // Grab NT header
    PIMAGE_NT_HEADERS64 imageNTHeader = reinterpret_cast<PIMAGE_NT_HEADERS64>(reinterpret_cast<DWORD_PTR>(imageDOSHeader) + imageDOSHeader->e_lfanew); // e_lfanew is the offset in bytes from the beginning of the DOS header to the NT headers

    // Grab file header
    IMAGE_FILE_HEADER imageFileHeader = imageNTHeader->FileHeader;

    // Grab optional header
    IMAGE_OPTIONAL_HEADER64 imageOptionalHeader = imageNTHeader->OptionalHeader;

    // Grab section header
    PIMAGE_SECTION_HEADER imageSectionHeader = reinterpret_cast<PIMAGE_SECTION_HEADER>(reinterpret_cast<DWORD_PTR>(imageNTHeader) + 0x04 + sizeof(IMAGE_FILE_HEADER) + imageFileHeader.SizeOfOptionalHeader); // +0x04 to skip NT signature

    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString("0x%1").arg(imageDOSHeader->e_magic, 0, 16)));

}

