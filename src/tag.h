#ifndef TAG_H
#define TAG_H

#include "defs.h"

class Tag{

   struct TagPrivateData{

	   Address     addr;
	   Identifier  nm; 
	   Properties  props 
	   //getter - setters?

   } * data;


   public:

    explicit Tag();


}

#endif //TAG_H
