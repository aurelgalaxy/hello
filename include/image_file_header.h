#ifndef IMAGE_FILE_HEADER_H
#define IMAGE_FILE_HEADER_H

#include <cstdint>
#include <fstream>

class IMAGE_FILE_HEADER
{
    std::uint16_t Machine;
    std::uint16_t NumberOfSections;
    std::uint32_t TimeDateStamp;
    std::uint32_t PointerToSymbolTable;
    std::uint32_t NumberOfSymbols;
    std::uint16_t SizeOfOptionalHeader;
    std::uint16_t Characteristics;
public:
    IMAGE_FILE_HEADER(std::ifstream& in);
};

#endif //IMAGE_FILE_HEADER_H
