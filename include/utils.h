#ifndef UTILS_H
#define UTILS_H

#include <cstdint>
#include <fstream>
#include <string>

std::uint8_t read8(std::ifstream& in);
std::uint16_t read16(std::ifstream& in);
std::uint32_t read32(std::ifstream& in);
std::string print8(std::uint8_t value);
std::string print16(std::uint16_t value);
std::string print32(std::uint32_t value);
std::uint16_t endian16(std::uint16_t value);
std::uint32_t endian32(std::uint32_t value);

#endif //UTILS_H
