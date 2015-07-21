#ifndef PROPERTY_H
#define PROPERTY_H

#include "../include/defs.h"
#include <set>

class Property;
class Attribute;

typedef std::set<Property> PropertySet;
typedef std::set<Attribute> AttributeSet;

struct Attribute{

		Identifier nm;
		Value      val;
};

class Property{

        PropertySet props;

        AttributeSet  attrs;


	public:
		Property(){
		}
};

#endif
