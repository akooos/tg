
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

        std::istream_iterator<std::string> isi{ss};
        std::istream_iterator<std::string> eos{};

        std::vector<std::string> vs{isi,eos};
        for(auto item: vs)
            std::cout << item;


    if(1)
        return 0;



    std::vector<char> ptrn ={'\n'};

    std::istreambuf_iterator<char> it(ss);
    //std::istreambuf_iterator<char> it_end();
/*

    std::cout << "iteration begin "  << std::endl;
    for( ; it != it_end; ++it){

        std::cout << *it ;
    }
    std::cout << std::endl;
    std::cout << "iteration end " << std::endl;
*/

    std::vector<char> result;


    // while( it != it_end ){

        //result = Tg::getNextPart(it,ptrn);

    std::vector <char> container;
    container.insert( container.begin(),
                      std::istreambuf_iterator<char>( ss ),
                      std::istreambuf_iterator<char>() );


      //  result = Tg::getNextPart(container.begin(),container.end(),ptrn);
        Tg::print(result);


//}



    return EXIT_SUCCESS;
}

