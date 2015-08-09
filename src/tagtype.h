#ifndef TAGTYPE_H
#define TAGTYPE_H

#include "property.h"

namespace Tg{

    class TagType{
        Identifier name;
        size_t len;
    };

    class TagTypeAlias : public TagType, public PropertyHandler{
        Identifier baseType;
        
    public:
      TagTypeAlias(const Identifier & baseTypeId ):baseType(baseTypeId){
        
      }
      
      const Identifier & getBaseType() const{
        return baseType;
      }
    };

    typedef std::vector<TagType> TagTypeVector;
}

#endif
