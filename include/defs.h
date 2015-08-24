#ifndef DEFS_H
#define DEFS_H

#include <locale>
#include <stdexcept>

#include <iostream>
#include <fstream>
#include <string>

#include <set>
#include <vector>
#include <deque>
#include <array>
#include  <iterator>

#include <algorithm>

#include <cassert>

#include "csingleton.h"

#ifdef USING_UNICODE
    #ifdef USING_BOOST
        #include <boost/locale.hpp>
    #else
        #include <codecvt>
    #endif
#endif


#define ITT(s) std::cout << __FILE__ << ":" <<__LINE__ << std::endl << s << std::endl;
//#ifndef DEBUG
#define NOT_YET_IMPLEMENTED throw std::logic_error("Not Yet Implemented!");
//#else
//#define NOT_YET_IMPLEMENTED	static_assert(0,"Not Yet Implemented!");
//#endif


namespace Tg{
  namespace Exceptions{
    const int E_ITEM_NOT_FOUND                         = -561;
    const int E_UNSUPPORTED_TEXT_ENCODING = -700;
    const int E_STREAM_READ_ERROR                  = -500;
  }
}
#endif // DEFS_H
