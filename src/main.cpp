
#include <cstdlib>
#include <iostream>

#include "utils.h"


#include <sstream>
#include <list>

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



    std::string part = Tg::getline(ss);
    std::cout  << "PART = " <<  part << std::endl;
    part = Tg::getline(ss);

    std::cout  << "PART = " <<part << std::endl;
    part = Tg::getline(ss);

    std::cout  << "PART = " <<part << std::endl;
    part = Tg::getline(ss);

    std::cout  << "PART = " <<part << std::endl;
    part = Tg::getline(ss);

    std::cout  << "PART = " <<part << std::endl;
    return EXIT_SUCCESS;
}

