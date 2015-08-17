
#include <cstdlib>
#include <iostream>

#include "utils.h"


#include <sstream>

int main(int argc, char** argv){


    std::stringstream ss;

    ss << "egy";
    ss << std::endl;
    ss << "ketto";
    ss << std::endl;
    ss << "harom";
    ss << std::endl;
    ss << "negy";
    ss << std::endl;
    ss << "ot";
    ss << std::endl;

    std::cout << "wtf" << std::endl;

    do{
      std::cout << "{1}" << std::endl;
       std::vector<char>  result =
Tg::getNextPart(ss,std::vector<char>() ={'\n'});
std::cout << "{2}" << std::endl;
        std::cout  << result.data() << std::endl;


    }while( ss.good() );

    return EXIT_SUCCESS;
}

