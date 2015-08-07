#ifndef PROPERTY_H
#define PROPERTY_H

#include <set>

#include "identifier.h"
#include "value.h"

namespace Tg{
    struct Parameter{
        Identifier id;
        Evaluable value;
        Parameter(const Identifier &id, const Evaluable &value):id(id),value(value){

        }
    };

    typedef std::set<Parameter> ParameterSet;

    struct Property;
    typedef std::set<Property> PropertySet;

    struct Property{
        PropertySet props;
        ParameterSet pars;
    };
}

#endif
