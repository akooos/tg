#ifdef STRUCTS_H
#define STRUCTS_H

#include <vector>

#include "property.h"


namespace Tg{

    struct Parameter{
        Identifier id;
        Evaluable value;
    };

    typedef std::set<Parameter> ParameterSet;

    struct Property;
    typedef std::set<Property> PropertySet;

    struct Property{
        PropertySet props;
        ParameterSet pars;
    };

    class TagTypeBase{

        Identifier name;
        size_t len;
    };

    class TagType : public TagTypeBase{
        Identifier baseType;
        PropertySet props;

    };

    typedef std::vector<TagTypeBase> TagTypeBaseVector;

    class TagStruct : public TagTypeBase{

            PropertySet props;            
            TagTypeBaseVector tts; 
    };

    class Tag{
        PropertySet props;
    };
    typedef std::vector<Tag> TagVector;

    class Group{

        Identifier name;
        TagVector tags;
    };
    typedef std::vector<Group> GroupVector;

    class Project{
        PropertySet props;
        GroupVector groups;



    };
}

#endif
