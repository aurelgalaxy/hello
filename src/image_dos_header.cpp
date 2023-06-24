#include "image_dos_header.h"
#include "utils.h"
#include <cassert>
#include <cstdint>
#include <fstream>

IMAGE_DOS_HEADER::IMAGE_DOS_HEADER(std::ifstream& in)
{
    in.read(e_magic,2);
    assert(!in.fail());
    assert((e_magic[0]=='M')&&(e_magic[1]=='Z'));
    e_cblp=endian16(read16(in));
    e_cp=endian16(read16(in));
    e_crlc=endian16(read16(in));
    e_cparhdr=endian16(read16(in));
    e_minalloc=endian16(read16(in));
    e_maxalloc=endian16(read16(in));
    e_ss=endian16(read16(in));
    e_sp=endian16(read16(in));
    e_csum=endian16(read16(in));
    e_ip=endian16(read16(in));
    e_cs=endian16(read16(in));
    e_lfarlc=endian16(read16(in));
    e_ovno=endian16(read16(in));
    for(std::size_t i=0;i<4;++i)
    {
        e_res[i]=endian16(read16(in));
    }
    e_oemid=endian16(read16(in));
    e_oeminfo=endian16(read16(in));
    for(std::size_t i=0;i<10;++i)
    {
        e_res2[i]=endian16(read16(in));
    }
    e_lfanew=endian16(read16(in));
}

std::uint16_t IMAGE_DOS_HEADER::get_e_lfanew() const
{
    return e_lfanew;
}
