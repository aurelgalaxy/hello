#include "image_optional_header32.h"
#include "utils.h"
#include <cstdint>
#include <fstream>

IMAGE_OPTIONAL_HEADER32::IMAGE_OPTIONAL_HEADER32(std::ifstream& in)
{
    Magic=endian16(read16(in));
    MajorLinkerVersion=read8(in);
    MinorLinkerVersion=read8(in);
    SizeOfCode=endian32(read32(in));
    SizeOfInitializedData=endian32(read32(in));
    SizeOfUninitializedData=endian32(read32(in));
    AddressOfEntryPoint=endian32(read32(in));
}

std::uint32_t IMAGE_OPTIONAL_HEADER32::getAddressOfEntryPoint() const
{
    return AddressOfEntryPoint;
}
