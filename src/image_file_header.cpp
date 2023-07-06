#include "image_file_header.h"
#include "utils.h"
#include <fstream>

IMAGE_FILE_HEADER::IMAGE_FILE_HEADER(std::ifstream& in)
{
    Machine=endian16(read16(in));
    NumberOfSections=endian16(read16(in));
    TimeDateStamp=endian32(read32(in));
    PointerToSymbolTable=endian32(read32(in));
    NumberOfSymbols=endian32(read32(in));
    SizeOfOptionalHeader=endian16(read16(in));
    Characteristics=endian16(read16(in));
}
