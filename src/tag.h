#ifndef TAG_H
#define TAG_H
#include <vector>
#include "property.h"

namespace Tg{
class Tag{
    Identifier name;
    PropertySet props;
};
typedef std::vector<Tag> TagVector;

}


#endif //TAG_H
