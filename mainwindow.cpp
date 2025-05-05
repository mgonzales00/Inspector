#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <cstddef>
#include <QString>
#include <QStyleFactory>
#include "PE32.h"
#include "debug.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    SetDarkMode();
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
        on_actionOpenFile_triggered();
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
        DisplayImage32();
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

// Add row to table

// 32 bit everything is DWORD or smaller, 64 bit everything is UNSIGNED LONG LONG or smaller
void MainWindow::AddTableRow(QTableWidget* table, int row, int column, unsigned long long value, size_t offset, size_t size)
{
    table->setItem(row, column, new QTableWidgetItem(QString("0x%1").arg(value, 0, 16)));
    table->setItem(row, column + 1, new QTableWidgetItem(QString("0x%1").arg(offset, 0, 16)));
    table->setItem(row, column + 2, new QTableWidgetItem(QString("0x%1").arg(size, 0, 16)));
}

void MainWindow::DisplayDOSHeader()
{
    // Treat DOS header like a WORD* so we can iterate through it
    WORD* dosHeaderMember = reinterpret_cast<WORD*>(pe32Image.GetDOSHeader());

    // Get number of words
    size_t numWords = sizeof(IMAGE_DOS_HEADER) / sizeof(WORD);
    for (size_t i = 0; i < numWords; ++i)
    {
        size_t memberOffset = i * sizeof(WORD);
        size_t memberSize = sizeof(dosHeaderMember[i]);
        AddTableRow(ui->dosHeaderTableWidget, i, 0, dosHeaderMember[i], memberOffset, memberSize);
    }
}

void MainWindow::DisplayNTHeaders()
{
    WORD* ntHeadersMember = reinterpret_cast<WORD*>(pe32Image.GetNTHeaders());

    // Get number of words
    size_t numWords = sizeof(IMAGE_NT_HEADERS32) / sizeof(WORD);
    for (size_t i = 0; i < numWords; ++i)
    {
        size_t memberOffset = i * sizeof(WORD);
        size_t memberSize = sizeof(ntHeadersMember[i]);
        AddTableRow(ui->ntHeadersTableWidget, i, 0, ntHeadersMember[i], memberOffset, memberSize);
    }
}

void MainWindow::DisplayFileHeader()
{

}

void MainWindow::DisplayOptionalHeader()
{

}

void MainWindow::DisplaySectionHeader()
{

}

void MainWindow::DisplayDataDirectories()
{

}

void MainWindow::DisplaySections()
{

}

void MainWindow::DisplayImports()
{

}

void MainWindow::DisplayImage32()
{
    DisplayDOSHeader();
    DisplayNTHeaders();
//    DisplayFileHeader();
//    DisplayOptionalHeader();
//    DisplaySectionHeader();
//    DisplayDataDirectories();
//    DisplaySections();
//    DisplayImports();
}

// 32-bit images
void MainWindow::ParseImage32(LPVOID imageBase)
{
    PE32 pe32(imageBase);
    pe32.Parse();
    pe32Image = pe32;
}

// 64-bit images
void MainWindow::ParseImage64(LPVOID imageBase)
{

}

void MainWindow::SetLightMode()
{
    QPalette lightPalette;
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    lightPalette.setColor(QPalette::Window, QColor(255, 255, 255));
    lightPalette.setColor(QPalette::WindowText, QColor(0, 0, 0));
    lightPalette.setColor(QPalette::Button, QColor(220, 220, 220));
    lightPalette.setColor(QPalette::ButtonText, QColor(0, 0, 0));
    lightPalette.setColor(QPalette::Base, QColor(255, 255, 255));
    lightPalette.setColor(QPalette::Text, QColor(0, 0, 0));
    lightPalette.setColor(QPalette::HighlightedText, QColor(255, 255, 255));
    lightPalette.setColor(QPalette::AlternateBase, QColor(245, 245, 245));
    QApplication::setPalette(lightPalette);
}

void MainWindow::SetDarkMode()
{
    QPalette darkPalette;
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::WindowText, QColor(255, 255, 255));
    darkPalette.setColor(QPalette::Button, QColor(64, 64, 64));
    darkPalette.setColor(QPalette::ButtonText, QColor(255, 255, 255));
    darkPalette.setColor(QPalette::Base, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::Text, QColor(255, 255, 255));
    darkPalette.setColor(QPalette::HighlightedText, QColor(0, 0, 0));
    darkPalette.setColor(QPalette::AlternateBase, QColor(75, 75, 75));
    QApplication::setPalette(darkPalette);
}

void MainWindow::on_actionToggleDarkMode_triggered()
{
    // Trigger light mode if dark mode is on
    if (darkModeOn)
    {
        SetLightMode();
        darkModeOn = false;
    }
    // Else trigger dark mode
    else
    {
        SetDarkMode();
        darkModeOn = true;
    }
}
