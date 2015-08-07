#ifndef TAGTYPE_H
#define TAGTYPE_H

#include <vector>
#include "property.h"

namespace Tg{

    class TagType{
        Identifier name;
        size_t len;
    };

    class TagTypeAlias : public TagType{
        Identifier baseType;
        PropertySet props;

    };

    typedef std::vector<TagType> TagTypeVector;
}

#endif
