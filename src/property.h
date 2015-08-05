#ifndef PROPERTY_H
#define PROPERTY_H

#include <set>

#include "identifier.h"
#include "value.h"

namespace Tg{

	struct Attribute{

		Tg::Identifier nm;
		Tg::Value      val;
	};

	typedef std::set<Attribute> AttributeSet;

	struct Property {

		typedef std::set<Property> PropertySet;
			PropertySet props;
			AttributeSet  attrs;
			Property(){
			}

	};

}

#endif
