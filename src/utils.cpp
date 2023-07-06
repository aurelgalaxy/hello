#include "utils.h"
#include <cassert>
#include <cstdint>
#include <fstream>
#include <sstream>
#include <string>

std::uint8_t read8(std::ifstream& in)
{
    char ch=static_cast<char>(in.get());
    assert(!in.fail());
    return static_cast<std::uint8_t>(ch);
}

std::uint16_t read16(std::ifstream& in)
{
    std::uint16_t high=static_cast<std::uint16_t>(read8(in));
    std::uint16_t low=static_cast<std::uint16_t>(read8(in));
    return ((high<<8)|(low));
}

std::uint32_t read32(std::ifstream& in)
{
    std::uint32_t high=static_cast<std::uint32_t>(read16(in));
    std::uint32_t low=static_cast<std::uint32_t>(read16(in));
    return ((high<<16)|(low));
}

std::string print8(std::uint8_t value)
{
    std::ostringstream out;
    out.width(2);
    out.fill('0');
    out<<std::hex<<((static_cast<int>(value))&0xff);
    return out.str();
}

std::string print16(std::uint16_t value)
{
    std::ostringstream out;
    out.width(4);
    out.fill('0');
    out<<std::hex<<value;
    return out.str();
}

std::string print32(std::uint32_t value)
{
    std::ostringstream out;
    out.width(8);
    out.fill('0');
    out<<std::hex<<value;
    return out.str();
}

std::uint16_t endian16(std::uint16_t value)
{
    std::uint16_t high=((value&0xff00)>>8);
    std::uint16_t low=(value&0x00ff);
    return ((low<<8)|(high));
}

std::uint32_t endian32(std::uint32_t value)
{
    std::uint32_t high=((value&0xffff0000)>>16);
    std::uint32_t low=(value&0x0000ffff);
    high=static_cast<std::uint32_t>(endian16(static_cast<std::uint16_t>(high)));
    low=static_cast<std::uint32_t>(endian16(static_cast<std::uint16_t>(low)));
    return ((low<<16)|(high));
}
