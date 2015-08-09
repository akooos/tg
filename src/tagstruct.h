#ifndef TAGSTRUCT_H
#define TAGSTRUCT_H

#include "tagtype.h"

namespace Tg{
    class TagStruct : public TagType, public PropertyHandler{
            
            TagTypeVector tts;
    };
}

#endif
