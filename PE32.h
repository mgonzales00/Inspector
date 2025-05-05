#ifndef PE32_H
#define PE32_H

#include <windows.h>
#include <vector>

class PE32
{
public:
    PE32()
    {

    }

    PE32(LPVOID _imageBase)
    {
        imageBase = _imageBase;
    }

    // Helper function to check if import is by ordinal
    inline bool IsImportByOrdinal(DWORD ordinal)
    {
        // MSB specifies whether import is by ordinal or by name
        // Non-zero value = import was by ordinal
        // Zero value = import was by name
        return (ordinal & IMAGE_ORDINAL_FLAG32) != 0;
    }

    // Helper function to extract ordinal value
    inline WORD GetOrdinalValue(DWORD ordinal)
    {
        // Extract ordinal number which is stored in lower 16 bits
        return static_cast<WORD>(ordinal & 0xFFFF);
    }

    PIMAGE_DOS_HEADER GetDOSHeader();
    PIMAGE_NT_HEADERS32 GetNTHeaders();
    PIMAGE_FILE_HEADER GetFileHeader();
    PIMAGE_OPTIONAL_HEADER32 GetOptionalHeader();
    PIMAGE_SECTION_HEADER GetSectionHeader();
    //std::vector<DWORD> GetDataDirectories();
\
    void ParseDOSHeader();
    void ParseNTHeader();
    void ParseFileHeader();
    void ParseOptionalHeader();
    void ParseSectionHeader();
    void ParseDataDirectories();
    void ParseSections();
    void ParseImports();
    void Parse();

private:
    LPVOID imageBase;
    PIMAGE_SECTION_HEADER importSection;
    PIMAGE_IMPORT_DESCRIPTOR importDescriptor;
    PIMAGE_THUNK_DATA32 thunkData;
    DWORD thunk;
    DWORD importDirectoryRVA;
    DWORD importDirectory;
    DWORD exportDirectory;
    PIMAGE_DOS_HEADER imageDOSHeader;
    PIMAGE_NT_HEADERS32 imageNTHeaders;
    PIMAGE_FILE_HEADER imageFileHeader;
    PIMAGE_OPTIONAL_HEADER32 imageOptionalHeader;
    PIMAGE_SECTION_HEADER imageSectionHeader;
    DWORD virtualSize;
    DWORD virtualAddr;
    std::vector<IMAGE_SECTION_HEADER> sections;
    std::vector<const char *> importNames;
    std::vector<WORD> funcNames;
    std::vector<WORD> ordinals;
    std::vector<DWORD> dataDirectories;
};

#endif // PE32_H
