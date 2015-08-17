﻿#ifndef DEFS_H
#define DEFS_H

#include <iostream>
#include <set>
#include <vector>
#include <deque>
#include <algorithm>
#include <locale>
#include <string>
#include <cassert>
#include <fstream>
#include <array>

#include "../src/utils.h"
#include "csingleton.h"


#ifdef USING_UNICODE
    #ifdef USING_BOOST
        #include <boost/locale.hpp>
    #else
        #include <codecvt>
    #endif
#endif

#include <string>
#include <stdexcept>
#ifndef DEBUG
#define NOT_YET_IMPLEMENTED throw std::logic_error("Not Yet Implemented!");
#else
#define NOT_YET_IMPLEMENTED	static_assert(0,"Not Yet Implemented!");
#endif

namespace Tg{



namespace Exceptions{
  const int E_ITEM_NOT_FOUND                         = -561;
  const int E_UNSUPPORTED_TEXT_ENCODING = -700;
  const int E_STREAM_READ_ERROR                  = -500;
}
}
#endif
