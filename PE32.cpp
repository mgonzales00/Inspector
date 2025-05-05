#include "PE32.h"
#include "debug.h"

PIMAGE_DOS_HEADER PE32::GetDOSHeader()
{
    return imageDOSHeader;
}

PIMAGE_NT_HEADERS32 PE32::GetNTHeaders()
{
    return imageNTHeaders;
}

PIMAGE_FILE_HEADER PE32::GetFileHeader()
{
    return imageFileHeader;
}

PIMAGE_OPTIONAL_HEADER32 PE32::GetOptionalHeader()
{
    return imageOptionalHeader;
}

//std::vector<DWORD> PE32::GetDataDirectories()
//{
//    return dataDirectories;
//}

void PE32::ParseDOSHeader()
{
    imageDOSHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(imageBase);
}

void PE32::ParseNTHeader()
{
    imageNTHeaders = reinterpret_cast<PIMAGE_NT_HEADERS32>(reinterpret_cast<DWORD_PTR>(imageDOSHeader) + imageDOSHeader->e_lfanew); // e_lfanew is the offset in bytes from the beginning of the DOS header to the NT headers
}

void PE32::ParseFileHeader()
{
    imageFileHeader = &imageNTHeaders->FileHeader;
}

void PE32::ParseOptionalHeader()
{
    imageOptionalHeader = &imageNTHeaders->OptionalHeader;
}

void PE32::ParseSectionHeader()
{
    imageSectionHeader = reinterpret_cast<PIMAGE_SECTION_HEADER>(reinterpret_cast<DWORD_PTR>(imageNTHeaders) + 0x04 + sizeof(IMAGE_FILE_HEADER) + imageFileHeader->SizeOfOptionalHeader); // +0x04 to skip NT signature
}

void PE32::ParseDataDirectories()
{
    importDirectory = imageNTHeaders->OptionalHeader.DataDirectory[0].VirtualAddress;
    exportDirectory = imageNTHeaders->OptionalHeader.DataDirectory[1].VirtualAddress;
    dataDirectories.push_back(importDirectory);
    dataDirectories.push_back(exportDirectory);
}

void PE32::ParseSections()
{
    PIMAGE_SECTION_HEADER sectionHeader = {};

    DWORD sectionSize = static_cast<DWORD>(sizeof(IMAGE_SECTION_HEADER)); // 40 bytes per header per section

    // RVA to import directory
    importDirectoryRVA = imageNTHeaders->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;

    // We want the address right after the optional header as the first section header starts there
    DWORD_PTR sectionBase = reinterpret_cast<DWORD_PTR>(imageNTHeaders) +
                        sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) +
                        imageNTHeaders->FileHeader.SizeOfOptionalHeader;

    for (int i = 0; i < imageNTHeaders->FileHeader.NumberOfSections; i++)
    {
        sectionHeader = reinterpret_cast<PIMAGE_SECTION_HEADER>(sectionBase + (i * sizeof(IMAGE_SECTION_HEADER)));
        sections.push_back(*sectionHeader);

        // Check if import directory falls within the bounds of the section we are iterating through
        if (importDirectoryRVA >= sectionHeader->VirtualAddress &&
            importDirectoryRVA < (sectionHeader->VirtualAddress + sectionHeader->Misc.VirtualSize))
        {
            importSection = sectionHeader;
        }
    }
}



void PE32::ParseImports()
{
    if (importSection == nullptr) {
        Debug("Alert", "Import section is null.");
        return;
    }

    // Get file offset to import table
    DWORD_PTR rawOffset = reinterpret_cast<DWORD_PTR>(imageBase) + importSection->PointerToRawData;

    // Get pointer to import descriptor's file offset (where the import directory lives in the raw file)
    // rawOffset = import table RVA
    // importDirectoryRVA = RVA of the import directory
    // importSection->VirtualAddress = VA of the import section (where the import section will be after loaded into memory)
    importDescriptor = reinterpret_cast<PIMAGE_IMPORT_DESCRIPTOR>(rawOffset + (importDirectoryRVA - importSection->VirtualAddress));

    for (; importDescriptor->Name != 0; importDescriptor++)
    {
        // File offset for name of import
        // import table + (location of name - virtual address)
        // basically import table + <RVA to name>
        importNames.push_back(reinterpret_cast<const char*>(rawOffset + (importDescriptor->Name - importSection->VirtualAddress)));

        // Thunks are used to resolve function calls and are found within the IAT.
        // When we want to execute a function from an external dll, the IAT will resolve the function using the respective thunk.
        if (importDescriptor->OriginalFirstThunk == 0)
            thunk = importDescriptor->FirstThunk;
        else
            thunk = importDescriptor->OriginalFirstThunk;

        // import table + <RVA to thunk>
        thunkData = reinterpret_cast<PIMAGE_THUNK_DATA32>(rawOffset + (thunk - importSection->VirtualAddress));

        for (; thunkData->u1.AddressOfData != 0; thunkData++)
        {
            if (thunkData->u1.AddressOfData > 0x80000000)
            {
                ordinals.push_back(thunkData->u1.AddressOfData);
            }
            else
            {
                funcNames.push_back(rawOffset + (thunkData->u1.AddressOfData - (importSection->VirtualAddress + 2)));
            }
        }
    }
}

void PE32::Parse()
{
    ParseDOSHeader();
    ParseNTHeader();
    ParseFileHeader();
    ParseOptionalHeader();
    ParseSectionHeader();
    ParseDataDirectories();
    ParseSections();
    ParseImports();
}
