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
<<<<<<< HEAD

=======
#include <fstream>
#include <array>
#include <memory>
>>>>>>> 82d5dfa2af3ab2da8f62480d89681352579b6291
#include "csingleton.h"

#ifdef USING_UNICODE
    #ifdef USING_BOOST
        #include <boost/locale.hpp>
    #else
        #include <codecvt>
    #endif
#endif

<<<<<<< HEAD
=======
#include <string>
#include <stdexcept>
#define NOT_YET_IMPLEMENTED throw std::logic_error("Not Yet Implemented!");

namespace Tg{
>>>>>>> 82d5dfa2af3ab2da8f62480d89681352579b6291

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
