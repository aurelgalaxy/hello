#include "image_dos_header.h"
#include "image_file_header.h"
#include "image_optional_header32.h"
#include "utils.h"
#include <cassert>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::ifstream in("example.exe");
    assert(!in.fail());
    IMAGE_DOS_HEADER imageDosHeader(in);
    assert(!in.fail());
    in.seekg(static_cast<std::ifstream::off_type>(imageDosHeader.get_e_lfanew()),std::ios_base::beg);
    assert(!in.fail());
    char Signature[4];
    in.read(Signature,4);
    assert(!in.fail());
    const std::string validSignature="PE\0\0";
    assert(Signature==validSignature);
    IMAGE_FILE_HEADER imageFileHeader(in);
    assert(!in.fail());
    IMAGE_OPTIONAL_HEADER32 imageOptionalHeader(in);
    assert(!in.fail());
    std::uint32_t entry=imageOptionalHeader.getAddressOfEntryPoint();
    std::cout<<"entry: 0x"<<print32(entry)<<'\n';
    in.seekg(static_cast<std::ifstream::off_type>(entry),std::ios_base::beg);
    assert(!in.fail());
    for(std::size_t i=0;i<16;++i)
    {
        std::cout<<' '<<print8(read8(in));
    }
}
