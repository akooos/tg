#ifndef PROJECT_H
#define PROJECT_H

#include "group.h"
#include "property.h"
namespace Tg{

class Project{
        Identifier name;
        PropertySet props;
        GroupVector groups;
        public:

            Project(){
            }
            /*!
             * Clears container, will be an empty project.
             */
            void clear(){
            }

            void setName(const Identifier &name){
                this.name = name;
            }

            const Identifier & getName() const{
                return this.name;
            }
            void setProperty(const Property & property){
                props.push_back(property);

            }
            const Property & getProperty(const Identifier &id) const{
                PropertySet::const_iterator it =  props.find(id);

                if ( props.end() != it ){
                    return *it;
                }

                E_DATA_NOT_FOUND

            }


    };
}
#endif
