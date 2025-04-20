#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <cstddef>
#include <QString>
#include <QStyleFactory>

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
    setDarkMode();
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
void AddTableRow(QTableWidget* table, int row, int column, unsigned long long value, size_t offset, size_t size)
{
    table->setItem(row, column, new QTableWidgetItem(QString("0x%1").arg(value, 0, 16)));
    table->setItem(row, column + 1, new QTableWidgetItem(QString("0x%1").arg(offset, 0, 16)));
    table->setItem(row, column + 2, new QTableWidgetItem(QString("0x%1").arg(size, 0, 16)));
}

// 32-bit images
void MainWindow::ParseImage32(LPVOID imageBase)
{   
    PIMAGE_SECTION_HEADER sectionHeader = {};
    PIMAGE_SECTION_HEADER importSection = {};
    PIMAGE_IMPORT_DESCRIPTOR importDescriptor = {};
    PIMAGE_THUNK_DATA32 thunkData = {};
    DWORD thunk = {};
    DWORD_PTR rawOffset = {};

    // Grab DOS header from within image
    PIMAGE_DOS_HEADER imageDOSHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(imageBase);

    // Grab NT header
    PIMAGE_NT_HEADERS32 imageNTHeaders = reinterpret_cast<PIMAGE_NT_HEADERS32>(reinterpret_cast<DWORD_PTR>(imageDOSHeader) + imageDOSHeader->e_lfanew); // e_lfanew is the offset in bytes from the beginning of the DOS header to the NT headers

    // Grab file header
    IMAGE_FILE_HEADER imageFileHeader = imageNTHeaders->FileHeader;

    // Grab optional header
    IMAGE_OPTIONAL_HEADER32 imageOptionalHeader = imageNTHeaders->OptionalHeader;

    // Grab section header
    PIMAGE_SECTION_HEADER imageSectionHeader = reinterpret_cast<PIMAGE_SECTION_HEADER>(reinterpret_cast<DWORD_PTR>(imageNTHeaders) + 0x04 + sizeof(IMAGE_FILE_HEADER) + imageFileHeader.SizeOfOptionalHeader); // +0x04 to skip NT signature


    // IMAGE_DOS_HEADER
    AddTableRow(ui->tableWidget, 0, 0, imageDOSHeader->e_magic, offsetof(IMAGE_DOS_HEADER, e_magic), sizeof(imageDOSHeader->e_magic));
    AddTableRow(ui->tableWidget, 1, 0, imageDOSHeader->e_cblp, offsetof(IMAGE_DOS_HEADER, e_cblp), sizeof(imageDOSHeader->e_cblp));
    AddTableRow(ui->tableWidget, 2, 0, imageDOSHeader->e_cp, offsetof(IMAGE_DOS_HEADER, e_cp), sizeof(imageDOSHeader->e_cp));
    AddTableRow(ui->tableWidget, 3, 0, imageDOSHeader->e_crlc, offsetof(IMAGE_DOS_HEADER, e_crlc), sizeof(imageDOSHeader->e_crlc));
    AddTableRow(ui->tableWidget, 4, 0, imageDOSHeader->e_cparhdr, offsetof(IMAGE_DOS_HEADER, e_cparhdr), sizeof(imageDOSHeader->e_cparhdr));
    AddTableRow(ui->tableWidget, 5, 0, imageDOSHeader->e_minalloc, offsetof(IMAGE_DOS_HEADER, e_minalloc), sizeof(imageDOSHeader->e_minalloc));
    AddTableRow(ui->tableWidget, 6, 0, imageDOSHeader->e_maxalloc, offsetof(IMAGE_DOS_HEADER, e_maxalloc), sizeof(imageDOSHeader->e_maxalloc));
    AddTableRow(ui->tableWidget, 7, 0, imageDOSHeader->e_ss, offsetof(IMAGE_DOS_HEADER, e_ss), sizeof(imageDOSHeader->e_ss));
    AddTableRow(ui->tableWidget, 8, 0, imageDOSHeader->e_sp, offsetof(IMAGE_DOS_HEADER, e_sp), sizeof(imageDOSHeader->e_sp));
    AddTableRow(ui->tableWidget, 9, 0, imageDOSHeader->e_csum, offsetof(IMAGE_DOS_HEADER, e_csum), sizeof(imageDOSHeader->e_csum));
    AddTableRow(ui->tableWidget, 10, 0, imageDOSHeader->e_ip, offsetof(IMAGE_DOS_HEADER, e_ip), sizeof(imageDOSHeader->e_ip));
    AddTableRow(ui->tableWidget, 11, 0, imageDOSHeader->e_cs, offsetof(IMAGE_DOS_HEADER, e_cs), sizeof(imageDOSHeader->e_cs));
    AddTableRow(ui->tableWidget, 12, 0, imageDOSHeader->e_lfarlc, offsetof(IMAGE_DOS_HEADER, e_lfarlc), sizeof(imageDOSHeader->e_lfarlc));
    AddTableRow(ui->tableWidget, 13, 0, imageDOSHeader->e_ovno, offsetof(IMAGE_DOS_HEADER, e_ovno), sizeof(imageDOSHeader->e_ovno));
    AddTableRow(ui->tableWidget, 14, 0, imageDOSHeader->e_oemid, offsetof(IMAGE_DOS_HEADER, e_oemid), sizeof(imageDOSHeader->e_oemid));
    AddTableRow(ui->tableWidget, 15, 0, imageDOSHeader->e_oeminfo, offsetof(IMAGE_DOS_HEADER, e_oeminfo), sizeof(imageDOSHeader->e_oeminfo));
    AddTableRow(ui->tableWidget, 16, 0, imageDOSHeader->e_lfanew, offsetof(IMAGE_DOS_HEADER, e_lfanew), sizeof(imageDOSHeader->e_lfanew));

    // IMAGE_NT_HEADERS
    AddTableRow(ui->tableWidget, 0, 0, imageNTHeaders->Signature, offsetof(IMAGE_NT_HEADERS, Signature), sizeof(imageNTHeaders->Signature));

    // FILE_HEADER
    AddTableRow(ui->fileHeaderTableWidget, 0, 0, imageNTHeaders->FileHeader.Machine, offsetof(IMAGE_FILE_HEADER, Machine), sizeof(imageNTHeaders->FileHeader.Machine));
    AddTableRow(ui->fileHeaderTableWidget, 1, 0, imageNTHeaders->FileHeader.NumberOfSections, offsetof(IMAGE_FILE_HEADER, NumberOfSections), sizeof(imageNTHeaders->FileHeader.NumberOfSections));
    AddTableRow(ui->fileHeaderTableWidget, 2, 0, imageNTHeaders->FileHeader.TimeDateStamp, offsetof(IMAGE_FILE_HEADER, TimeDateStamp), sizeof(imageNTHeaders->FileHeader.TimeDateStamp));
    AddTableRow(ui->fileHeaderTableWidget, 3, 0, imageNTHeaders->FileHeader.PointerToSymbolTable, offsetof(IMAGE_FILE_HEADER, PointerToSymbolTable), sizeof(imageNTHeaders->FileHeader.PointerToSymbolTable));
    AddTableRow(ui->fileHeaderTableWidget, 4, 0, imageNTHeaders->FileHeader.NumberOfSymbols, offsetof(IMAGE_FILE_HEADER, NumberOfSymbols), sizeof(imageNTHeaders->FileHeader.NumberOfSymbols));
    AddTableRow(ui->fileHeaderTableWidget, 5, 0, imageNTHeaders->FileHeader.SizeOfOptionalHeader, offsetof(IMAGE_FILE_HEADER, SizeOfOptionalHeader), sizeof(imageNTHeaders->FileHeader.SizeOfOptionalHeader));
    AddTableRow(ui->fileHeaderTableWidget, 6, 0, imageNTHeaders->FileHeader.Characteristics, offsetof(IMAGE_FILE_HEADER, Characteristics), sizeof(imageNTHeaders->FileHeader.Characteristics));

    // OPTIONAL_HEADER
    AddTableRow(ui->optionalHeaderTableWidget, 0, 0, imageOptionalHeader.Magic, offsetof(IMAGE_OPTIONAL_HEADER, Magic), sizeof(imageOptionalHeader.Magic));
    AddTableRow(ui->optionalHeaderTableWidget, 1, 0, imageOptionalHeader.MajorLinkerVersion, offsetof(IMAGE_OPTIONAL_HEADER, MajorLinkerVersion), sizeof(imageOptionalHeader.MajorLinkerVersion));
    AddTableRow(ui->optionalHeaderTableWidget, 2, 0, imageOptionalHeader.MinorLinkerVersion, offsetof(IMAGE_OPTIONAL_HEADER, MinorLinkerVersion), sizeof(imageOptionalHeader.MinorLinkerVersion));
    AddTableRow(ui->optionalHeaderTableWidget, 3, 0, imageOptionalHeader.SizeOfCode, offsetof(IMAGE_OPTIONAL_HEADER, SizeOfCode), sizeof(imageOptionalHeader.SizeOfCode));
    AddTableRow(ui->optionalHeaderTableWidget, 4, 0, imageOptionalHeader.SizeOfInitializedData, offsetof(IMAGE_OPTIONAL_HEADER, SizeOfInitializedData), sizeof(imageOptionalHeader.SizeOfInitializedData));
    AddTableRow(ui->optionalHeaderTableWidget, 5, 0, imageOptionalHeader.SizeOfUninitializedData, offsetof(IMAGE_OPTIONAL_HEADER, SizeOfUninitializedData), sizeof(imageOptionalHeader.SizeOfUninitializedData));
    AddTableRow(ui->optionalHeaderTableWidget, 6, 0, imageOptionalHeader.AddressOfEntryPoint, offsetof(IMAGE_OPTIONAL_HEADER, AddressOfEntryPoint), sizeof(imageOptionalHeader.AddressOfEntryPoint));
    AddTableRow(ui->optionalHeaderTableWidget, 7, 0, imageOptionalHeader.BaseOfCode, offsetof(IMAGE_OPTIONAL_HEADER, BaseOfCode), sizeof(imageOptionalHeader.BaseOfCode));

    // Base of data is 32 bit only
    IMAGE_OPTIONAL_HEADER32* optHeader32 = reinterpret_cast<IMAGE_OPTIONAL_HEADER32*>(&imageOptionalHeader);
    AddTableRow(ui->optionalHeaderTableWidget, 8, 0, optHeader32->BaseOfData, offsetof(IMAGE_OPTIONAL_HEADER32, BaseOfData), sizeof(optHeader32->BaseOfData));

    AddTableRow(ui->optionalHeaderTableWidget, 9,  0, imageOptionalHeader.ImageBase, offsetof(IMAGE_OPTIONAL_HEADER, ImageBase), sizeof(imageOptionalHeader.ImageBase));
    AddTableRow(ui->optionalHeaderTableWidget, 10, 0, imageOptionalHeader.SectionAlignment, offsetof(IMAGE_OPTIONAL_HEADER, SectionAlignment), sizeof(imageOptionalHeader.SectionAlignment));
    AddTableRow(ui->optionalHeaderTableWidget, 11, 0, imageOptionalHeader.FileAlignment, offsetof(IMAGE_OPTIONAL_HEADER, FileAlignment), sizeof(imageOptionalHeader.FileAlignment));
    AddTableRow(ui->optionalHeaderTableWidget, 12, 0, imageOptionalHeader.MajorOperatingSystemVersion, offsetof(IMAGE_OPTIONAL_HEADER, MajorOperatingSystemVersion), sizeof(imageOptionalHeader.MajorOperatingSystemVersion));
    AddTableRow(ui->optionalHeaderTableWidget, 13, 0, imageOptionalHeader.MinorOperatingSystemVersion, offsetof(IMAGE_OPTIONAL_HEADER, MinorOperatingSystemVersion), sizeof(imageOptionalHeader.MinorOperatingSystemVersion));
    AddTableRow(ui->optionalHeaderTableWidget, 14, 0, imageOptionalHeader.MajorImageVersion, offsetof(IMAGE_OPTIONAL_HEADER, MajorImageVersion), sizeof(imageOptionalHeader.MajorImageVersion));
    AddTableRow(ui->optionalHeaderTableWidget, 15, 0, imageOptionalHeader.MinorImageVersion, offsetof(IMAGE_OPTIONAL_HEADER, MinorImageVersion), sizeof(imageOptionalHeader.MinorImageVersion));
    AddTableRow(ui->optionalHeaderTableWidget, 16, 0, imageOptionalHeader.MajorSubsystemVersion, offsetof(IMAGE_OPTIONAL_HEADER, MajorSubsystemVersion), sizeof(imageOptionalHeader.MajorSubsystemVersion));
    AddTableRow(ui->optionalHeaderTableWidget, 17, 0, imageOptionalHeader.MinorSubsystemVersion, offsetof(IMAGE_OPTIONAL_HEADER, MinorSubsystemVersion), sizeof(imageOptionalHeader.MinorSubsystemVersion));
    AddTableRow(ui->optionalHeaderTableWidget, 18, 0, imageOptionalHeader.Win32VersionValue, offsetof(IMAGE_OPTIONAL_HEADER, Win32VersionValue), sizeof(imageOptionalHeader.Win32VersionValue));
    AddTableRow(ui->optionalHeaderTableWidget, 19, 0, imageOptionalHeader.SizeOfImage, offsetof(IMAGE_OPTIONAL_HEADER, SizeOfImage), sizeof(imageOptionalHeader.SizeOfImage));
    AddTableRow(ui->optionalHeaderTableWidget, 20, 0, imageOptionalHeader.SizeOfHeaders, offsetof(IMAGE_OPTIONAL_HEADER, SizeOfHeaders), sizeof(imageOptionalHeader.SizeOfHeaders));
    AddTableRow(ui->optionalHeaderTableWidget, 21, 0, imageOptionalHeader.CheckSum, offsetof(IMAGE_OPTIONAL_HEADER, CheckSum), sizeof(imageOptionalHeader.CheckSum));
    AddTableRow(ui->optionalHeaderTableWidget, 22, 0, imageOptionalHeader.Subsystem, offsetof(IMAGE_OPTIONAL_HEADER, Subsystem), sizeof(imageOptionalHeader.Subsystem));
    AddTableRow(ui->optionalHeaderTableWidget, 23, 0, imageOptionalHeader.DllCharacteristics, offsetof(IMAGE_OPTIONAL_HEADER, DllCharacteristics), sizeof(imageOptionalHeader.DllCharacteristics));
    AddTableRow(ui->optionalHeaderTableWidget, 24, 0, imageOptionalHeader.SizeOfStackReserve, offsetof(IMAGE_OPTIONAL_HEADER, SizeOfStackReserve), sizeof(imageOptionalHeader.SizeOfStackReserve));
    AddTableRow(ui->optionalHeaderTableWidget, 25, 0, imageOptionalHeader.SizeOfStackCommit, offsetof(IMAGE_OPTIONAL_HEADER, SizeOfStackCommit), sizeof(imageOptionalHeader.SizeOfStackCommit));
    AddTableRow(ui->optionalHeaderTableWidget, 26, 0, imageOptionalHeader.SizeOfHeapReserve, offsetof(IMAGE_OPTIONAL_HEADER, SizeOfHeapReserve), sizeof(imageOptionalHeader.SizeOfHeapReserve));
    AddTableRow(ui->optionalHeaderTableWidget, 27, 0, imageOptionalHeader.SizeOfHeapCommit, offsetof(IMAGE_OPTIONAL_HEADER, SizeOfHeapCommit), sizeof(imageOptionalHeader.SizeOfHeapCommit));
    AddTableRow(ui->optionalHeaderTableWidget, 28, 0, imageOptionalHeader.LoaderFlags, offsetof(IMAGE_OPTIONAL_HEADER, LoaderFlags), sizeof(imageOptionalHeader.LoaderFlags));

    // DATA_DIRECTORIES
    // EXPORT DIRECTORY ADDRESS
    AddTableRow(ui->dataDirectoriesTableWidget, 0, 0,
        imageNTHeaders->OptionalHeader.DataDirectory[0].VirtualAddress,
        offsetof(IMAGE_OPTIONAL_HEADER, DataDirectory) + 0 * sizeof(IMAGE_DATA_DIRECTORY) + offsetof(IMAGE_DATA_DIRECTORY, VirtualAddress),
        sizeof(imageNTHeaders->OptionalHeader.DataDirectory[0].VirtualAddress)
        );

    // IMPORT DIRECTORY ADDRESS
    AddTableRow(ui->dataDirectoriesTableWidget, 1, 0,
        imageNTHeaders->OptionalHeader.DataDirectory[1].VirtualAddress,
        offsetof(IMAGE_OPTIONAL_HEADER, DataDirectory) + 1 * sizeof(IMAGE_DATA_DIRECTORY) + offsetof(IMAGE_DATA_DIRECTORY, VirtualAddress),
        sizeof(imageNTHeaders->OptionalHeader.DataDirectory[1].VirtualAddress)
        );

    // SECTION_HEADERS
    // We want the address right after the optional header as the first section header starts there
    DWORD sectionLocation =
        reinterpret_cast<uintptr_t>(imageNTHeaders) + // Start at PE headers
        sizeof(DWORD) +  // Skip the PE signature
                            static_cast<DWORD>(sizeof(IMAGE_FILE_HEADER)) + // Skip the file header
                            static_cast<DWORD>(imageNTHeaders->FileHeader.SizeOfOptionalHeader); // Skip optional header
    DWORD sectionSize = static_cast<DWORD>(sizeof(IMAGE_SECTION_HEADER)); // 40 bytes per header per section

    // RVA to import directory
    DWORD importDirectoryRVA = imageNTHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;

    PBYTE sectionBase = reinterpret_cast<BYTE*>(imageNTHeaders) +
                        sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) +
                        imageNTHeaders->FileHeader.SizeOfOptionalHeader;

    for (int i = 0; i < imageNTHeaders->FileHeader.NumberOfSections; i++)
    {
        sectionHeader = reinterpret_cast<PIMAGE_SECTION_HEADER>(sectionBase + (i * sizeof(IMAGE_SECTION_HEADER)));

        // From BYTE[8] -> const char*
        QString sectionNameStr = QString::fromLatin1(reinterpret_cast<const char*>(sectionHeader->Name), 8).trimmed();
        QString virtualSizeStr = QString("0x%1").arg(sectionHeader->Misc.VirtualSize, 0, 16);
        QString virtualAddrStr = QString("0x%1").arg(sectionHeader->VirtualAddress, 0, 16);
        QString sizeOfRawDataStr = QString("0x%1").arg(sectionHeader->SizeOfRawData, 0, 16);
        QString ptrToRawDataStr = QString("0x%1").arg(sectionHeader->PointerToRawData, 0, 16);
        QString ptrToRelocStr = QString("0x%1").arg(sectionHeader->PointerToRelocations, 0, 16);
        QString ptrToLineNumStr = QString("0x%1").arg(sectionHeader->PointerToLinenumbers, 0, 16);
        QString numOfLineNum = QString("0x%1").arg(sectionHeader->NumberOfLinenumbers, 0, 16);
        QString numOfRelocStr = QString("0x%1").arg(sectionHeader->NumberOfRelocations, 0, 16);
        QString characterStr = QString("0x%1").arg(sectionHeader->Characteristics, 0, 16);

        // Create a single list item for all the strings (combining all section info into one string)
        QString sectionInfo = QString(
                                  "Section Name: %1\n"
                                  "Virtual Size: %2\n"
                                  "Virtual Address: %3\n"
                                  "Size of Raw Data: %4\n"
                                  "Pointer to Raw Data: %5\n"
                                  "Pointer to Relocations: %6\n"
                                  "Pointer to Line Numbers: %7\n"
                                  "Number of Line Numbers: %8\n"
                                  "Number of Relocations: %9\n"
                                  "Characteristics: %10\n")
                                  .arg(sectionNameStr)
                                  .arg(virtualSizeStr)
                                  .arg(virtualAddrStr)
                                  .arg(sizeOfRawDataStr)
                                  .arg(ptrToRawDataStr)
                                  .arg(ptrToRelocStr)
                                  .arg(ptrToLineNumStr)
                                  .arg(numOfLineNum)
                                  .arg(numOfRelocStr)
                                  .arg(characterStr);

        // Create the list item and add it to the list view
        QListWidgetItem* item = new QListWidgetItem(sectionInfo);
        ui->sectionHeaderListWidget->addItem(item);

        // Check if import directory is within range of .text section
        // we want to make sure the import directory RVA is greater than the base address of the .text section AND that it's below the end of the .text section
        if (importDirectoryRVA >= sectionHeader->VirtualAddress &&
            importDirectoryRVA < (sectionHeader->VirtualAddress + sectionHeader->Misc.VirtualSize))
        {
            importSection = sectionHeader;
        }
        sectionLocation += sectionSize;
    }

    if (importSection == nullptr) {
        Debug("Alert", "Import section is null.");
        return;
    }

    // Get file offset to import table
    rawOffset = reinterpret_cast<DWORD_PTR>(imageBase) + importSection->PointerToRawData;

    // Get pointer to import descriptor's file offset (where the import directory lives in the raw file)
    // rawOffset = import table RVA
    // importDirectoryRVA = RVA of the import directory
    // importSection->VirtualAddress = VA of the import section (where the import section will be after loaded into memory)
    importDescriptor = reinterpret_cast<PIMAGE_IMPORT_DESCRIPTOR>(rawOffset + (importDirectoryRVA - importSection->VirtualAddress));


    QString dllImportTitleStr = "****** FUNCTION IMPORTS ******";
    QListWidgetItem* item = new QListWidgetItem(dllImportTitleStr);
    ui->dllImportListWidget->addItem(item);

    for (; importDescriptor->Name != 0; importDescriptor++)
    {
        // File offset for name of import
        // import table + (location of name - virtual address)
        // basically import table + <RVA to name>
        QString dllImportName = QString::fromLatin1(reinterpret_cast<const char*>(rawOffset + (importDescriptor->Name - importSection->VirtualAddress)));
        ui->dllImportListWidget->addItem(dllImportName);

        // Thunks are used to resolve function calls and are found within the IAT.
        // When we want to execute a function from an external dll, the IAT will resolve the function using the respective thunk.
        if (importDescriptor->OriginalFirstThunk == 0)
            thunk = importDescriptor->FirstThunk;
        else
            thunk = importDescriptor->OriginalFirstThunk;

        thunkData = reinterpret_cast<PIMAGE_THUNK_DATA32>(rawOffset + (thunk - importSection->VirtualAddress));

        for (; thunkData->u1.AddressOfData != 0; thunkData++)
        {
            if (thunkData->u1.AddressOfData > 0x80000000)
            {
                QString ordinalStr = QString("Ordinal: 0x%1").arg(static_cast<WORD>(thunkData->u1.AddressOfData));
                ui->dllImportListWidget->addItem(ordinalStr);
            }
            else
            {
                QString funcNameStr = QString("0x%1").arg(rawOffset + (thunkData->u1.AddressOfData - importSection->VirtualAddress + 2));
                ui->dllImportListWidget->addItem(funcNameStr);
            }
        }
    }
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

void MainWindow::setLightMode()
{
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QPalette lightPalette;
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

void MainWindow::setDarkMode()
{
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    QPalette darkPalette;
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
        setLightMode();
        darkModeOn = false;
    }
    // Else trigger dark mode
    else {
        setDarkMode();
        darkModeOn = true;
    }
}

