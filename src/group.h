#ifndef GROUP_H
#define GROUP_H

#include "tag.h"

namespace Tg{

class Group;
typedef std::deque<Group> GroupList;

/*!
 * This group is not the same as a "tag group" in a system.
 * Just a group of tags with some same properties.
 * Tag group should be a property.
 */
class Group : public PropertyHandler{ 
        TagList tags;
        GroupList groups;
    public:
      
};

}

#endif


