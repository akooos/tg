#ifndef DEFS_H
#define DEFS_H

#include <iostream>

#ifdef USING_UNICODE
    #ifdef USING_BOOST
        #include <boost/locale.hpp>
    #else
        #include <locale>
        #include <codecvt>
    #endif
#endif

#include <string>
#include <stdexcept>
#define NOT_YET_IMPLEMENTED	throw std::logic_error("Not yet implemented.");

#endif
