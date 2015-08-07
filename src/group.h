#ifndef GROUP_H
#define GROUP_H

#include "tag.h"

namespace Tg{

class Group; 
typedef std::vector<Group> GroupVector;

/*!
 * This group is not the same as a "tag group" in a system.
 * Just a group of tags with some same properties.
 * Tag group should be a property.
 *
 */
class Group{
        Identifier name;
        PropertySet props;
        TagVector tags;
        GroupVector groups;
};

}

#endif


