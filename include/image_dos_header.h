#ifndef IMAGE_DOS_HEADER_H
#define IMAGE_DOS_HEADER_H

#include <cstdint>
#include <fstream>

class IMAGE_DOS_HEADER
{
    char e_magic[2];
    std::uint16_t e_cblp;
    std::uint16_t e_cp;
    std::uint16_t e_crlc;
    std::uint16_t e_cparhdr;
    std::uint16_t e_minalloc;
    std::uint16_t e_maxalloc;
    std::uint16_t e_ss;
    std::uint16_t e_sp;
    std::uint16_t e_csum;
    std::uint16_t e_ip;
    std::uint16_t e_cs;
    std::uint16_t e_lfarlc;
    std::uint16_t e_ovno;
    std::uint16_t e_res[4];
    std::uint16_t e_oemid;
    std::uint16_t e_oeminfo;
    std::uint16_t e_res2[10];
    std::uint16_t e_lfanew;
public:
    IMAGE_DOS_HEADER(std::ifstream& in);
    std::uint16_t get_e_lfanew() const;
};

#endif //IMAGE_DOS_HEADER_H
