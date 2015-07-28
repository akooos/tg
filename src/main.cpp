#include <cstdlib>
#include <iostream>
#include "utils.h"
#include <string>
#include <locale>
#include <sstream>
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
        return EXIT_SUCCESS;
}

