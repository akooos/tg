#ifndef PROJECT_H
#define PROJECT_H

#include "group.h"
#include "property.h"
namespace Tg
{

class Project : public PropertyHandler
{

    GroupList groups;
public:

    Project() {
    }
    /*!
     * Clears container, will be an empty project.
     */
    void clear() {
        lsProps.clear();
        groups.clear();
        id = "";
    }




};
}
#endif
