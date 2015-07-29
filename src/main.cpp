#include <cstdlib>
#include <iostream>
#include "utils.h"
#include <string>
#include <locale>
#include <sstream>
#include "identifier.h"
int main(int argc, char** argv){

    std::cout << "Starting up..." << std::endl;
    std::u16string str = Utils::utf8ToUtf16(u8"Óh mary itt egy pökcet súp őőő");
    std::ios_base::sync_with_stdio(false);
    std::locale hu("hu_HU.utf8");

    //		std::wcout.imbue(hu);
    //		std::cout << str.c_str()<< std::endl;
    //		std::wcout << L"áááééőőúóöüü"<< std::endl;
    std::wstringstream in{ L"áááééőőúóöüü"};
    in.imbue(hu);
    std::wcout.imbue(hu);
    std::wstring word;
    unsigned wordcount = 0;
    while (in >> word) {
        std::wcout << wordcount << ": \"" << word << "\"\n";
        ++wordcount;

    }

    Tg::Identifier id(std::string("azon"));
    std::wstring s = id.toWideString();
    std::wcout << s.size() << std::endl;
    std::wcout << s.length() << std::endl;
    std::cout << s[0] << std::endl;
    std::cout << sizeof(s[0])<< std::endl;
    std::wcout << s << std::endl;
    
    return EXIT_SUCCESS;
}

