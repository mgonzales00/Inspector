#ifndef PE64_H
#define PE64_H

#include <windows.h>

class PE64
{
public:
    PE64(LPVOID imageBase);

    void ParseDOSHeader();
    void ParseNTHeader();
    void ParseFileHeader();
    void ParseOptionalHeader();
    void ParseDataDirectories();
    void ParseSections();
    void ParseImports();
    void ParsePEFile();
    void PrintDOSHeader();
    void PrintNTHeader();
    void PrintFileHeader();
    void PrintOptionalHeader();
    void PrintDataDirectories();
    void PrintSections();
    void PrintImports();
    void Print();

private:
    PIMAGE_SECTION_HEADER sectionHeader;
    PIMAGE_SECTION_HEADER importSection;
    PIMAGE_IMPORT_DESCRIPTOR importDescriptor;
    PIMAGE_THUNK_DATA64 thunkData;
    DWORD thunk;
    DWORD_PTR rawOffset;
    PIMAGE_DOS_HEADER imageDOSHeader;
    PIMAGE_NT_HEADERS64 imageNTHeaders;
    IMAGE_FILE_HEADER imageFileHeader;
    IMAGE_OPTIONAL_HEADER64 imageOptionalHeader;
    PIMAGE_SECTION_HEADER imageSectionHeader;
};

#endif // PE64_H
