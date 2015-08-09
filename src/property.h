#ifndef PROPERTY_H
#define PROPERTY_H

#include "identifier.h"
#include "value.h"

namespace Tg{
  
  
    class Property : public Evaluable{
        Identifier id;	
        Evaluable value;
    public:
        Property(const Identifier &id, const Evaluable &value):id(id),value(value){

        }
        const Identifier & getIdentifier() const{
          return id;
        }
        
    }; 
    typedef std::deque<Property> PropertyList;
    
    class PropertyHandler{
      
      struct PropertyIdMatcher{
        const Identifier &id;
        PropertyIdMatcher(const Identifier &id):id(id){}
        bool operator() (const Property & pim) const{
          return  id == pim.getIdentifier();
        }
      };
    protected:
      
      Identifier   id;
      PropertyList lsProps;
    public:
      
      inline const Identifier & getName(){
        return id;
      }
      inline bool setProperty(
        
        const Property &p)
      {
        if ( hasProperty(p) )
          return false;
        
        lsProps.push_back(p);
        
        return true;
        
      }
      
      inline bool hasProperty(
        const Identifier &id) const
      {
        PropertyIdMatcher pim(id);
        
        PropertyList::const_iterator it = 
        std::find_if(lsProps.begin(),lsProps.end(),pim);
        
        return ( lsProps.end() != it );
      }
      inline bool hasProperty(
        const Property &prop) const
      {
        PropertyIdMatcher pim(prop.getIdentifier());
        
        PropertyList::const_iterator it = 
        std::find_if(lsProps.begin(),lsProps.end(),pim);
        
        return ( lsProps.end() != it );
      }
      /*!
       *  Checks if property list has a property with id identifier and will 
          returns the property on match, otherwise
       * throws an exception(Tg::Exceptions::E_ITEM_NOT_FOUND).
       */
      const Property & isSupportedPropertyType(
        const Identifier &id) const
      {
        
        PropertyIdMatcher pim(id);
        
        PropertyList::const_iterator it = 
        std::find_if(lsProps.begin(),lsProps.end(),pim);
        
        if ( lsProps.end() != it )
          return *it;
        
        throw Tg::Exceptions::E_ITEM_NOT_FOUND;
      }
       
       
    };

}



#endif
