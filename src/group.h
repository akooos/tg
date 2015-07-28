#ifndef GROUP_H
#define GROUP_H

#include "tag.h"
class Group;

typedef std::set<Group> GroupSet;


class Group{
   Identifier nm;
   PropertySet props;
   GroupSet    grps;
};


#endif


