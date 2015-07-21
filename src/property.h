#ifndef PROPERTY_H
#define PROPERTY_H

#include "../include/defs.h"

#include <set>

class Property;
class Attribute;

typedef std::set<Property> PropertieSet;
typedef std::set<Attribute> AttributeSet;

struct Attribute{

		Identifier nm;
		Value      val;
};

class Property{

	struct PropertyPrivateData{
		//sub properties
        PropertieSet props;

        AttributeSet  attrs;

	} * data;

	public:
		Property(){
		}
};

#endif
