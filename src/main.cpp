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

std::uint32_t readEntryPoint(std::ifstream& in)
{
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
    in.seekg(static_cast<std::ifstream::off_type>(entry),std::ios_base::beg);
    return entry;
}

void old_main()
{
    std::ifstream in("example.exe");
    assert(!in.fail());
    std::uint32_t entry=readEntryPoint(in);
    assert(!in.fail());
    std::cout<<"entry: 0x"<<print32(entry)<<'\n';
    for(std::size_t i=0;i<16;++i)
    {
        std::cout<<' '<<print8(read8(in));
    }
}

class OpcodeLine
{
    std::string address;
    std::string opcodes;
    std::string instruction;
    std::string arguments;
public:
    OpcodeLine(const std::string& line);
    std::string getOpcodes() const;
    std::string getAssembly() const;
};

OpcodeLine::OpcodeLine(const std::string& line)
{
    const std::size_t opcodeSize=3;
    const std::size_t opcodeCount=7;
    const std::size_t opcodeChars=opcodeSize*opcodeCount;
    if((line.size()>=18+opcodeChars)&&(line.substr(0,2)=="  "))
    {
        address=line.substr(2,6);
        assert(line.substr(8,2)==":\t");
        opcodes=line.substr(10,opcodeChars);
        std::size_t spacesPos=opcodes.find("  ");
        if(spacesPos!=std::string::npos)
        {
            opcodes=opcodes.substr(0,spacesPos);
        }
        assert(line[10+opcodeChars]=='\t');
        instruction=line.substr(11+opcodeChars,7);
        spacesPos=instruction.find(' ');
        if(spacesPos!=std::string::npos)
        {
            instruction=instruction.substr(0,spacesPos);
        }
        arguments=line.substr(18+opcodeChars);
    }
}

std::string OpcodeLine::getOpcodes() const
{
    return opcodes;
}

std::string OpcodeLine::getAssembly() const
{
    return instruction+((arguments.empty())?(""):(" "+arguments));
}

int main()
{
    std::ifstream in("opcodes.txt");
    assert(!in.fail());
    std::string line;
    while(std::getline(in,line))
    {
        OpcodeLine opcodeLine(line);
        std::string opcodes=opcodeLine.getOpcodes();
        if(!opcodes.empty())
        {
            std::cout<<"\""<<opcodes<<"\"=\""<<opcodeLine.getAssembly()<<"\"\n";
        }
    }
}
