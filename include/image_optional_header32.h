#ifndef IMAGE_OPTIONAL_HEADER32_H
#define IMAGE_OPTIONAL_HEADER32_H

#include <cstdint>
#include <fstream>

class IMAGE_OPTIONAL_HEADER32
{
    std::uint16_t Magic;
    std::uint8_t MajorLinkerVersion;
    std::uint8_t MinorLinkerVersion;
    std::uint32_t SizeOfCode;
    std::uint32_t SizeOfInitializedData;
    std::uint32_t SizeOfUninitializedData;
    std::uint32_t AddressOfEntryPoint;
public:
    IMAGE_OPTIONAL_HEADER32(std::ifstream& in);
    std::uint32_t getAddressOfEntryPoint() const;
};

#endif //IMAGE_OPTIONAL_HEADER32_H
