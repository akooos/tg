#ifndef TAGSYSTEM_H
#define TAGSYSTEM_H

#include "identifier.h"
#include "value.h"
#include "project_file_handler.h"
namespace Tg{

 namespace TagSystems{
/*! Property's value type in the tagsystem. */
enum PropertyValueType{ Int, Float, String, Enum, PropertyGroup };




class PropertyInfo;
typedef std::deque<PropertyInfo> PropertyInfoList;

class PropertyInfo{
  
  Identifier id;
  PropertyValueType pvt;
  /*! Possible values, this fields exists because of Enum property value type, and for error checking.*/
  EvaluableList pvs;
  /*! Normally there is no need for multiple level of properties, but still should be possible for cleaner look.*/
  PropertyInfoList subprops;

  /*!
   * Property can be applied for specific types...Restrict the 
      property scope usage. 
      Empty set means "everywhere". 
   */
  IdentifierSet  appliedFor;
  
  
public:
  /*!
   * Use this constructor if you need a property that HAS sub properties.
   */
    PropertyInfo(
        const Identifier &id,
        const PropertyInfoList &subprops,
        const IdentifierSet    &appliedFor = IdentifierSet()
        
        ):id(id),
          pvt(PropertyGroup),
          subprops(subprops),
          appliedFor(appliedFor){}
    /*!
     * Use this constructor if you need a property that HAS NO sub 
        propertvoiies.
   */
    PropertyInfo(
      const Identifier &id,
      PropertyValueType pvt,
      const EvaluableList &pvs = EvaluableList(),
      const IdentifierSet    &appliedFor = IdentifierSet()
      ):id(id),pvt(pvt),pvs(pvs),appliedFor(appliedFor){}
    
     PropertyValueType getPropertyValueType() const{
       return pvt;
     }
     const EvaluableList & getPossibleValues() const{
       return pvs;
     }
     const PropertyInfoList & getSubProps() const{
       return subprops;
     }
     const IdentifierSet  & getIdentifierSet() const{
       return appliedFor;
    }
     const Identifier & getName() const{
       return id;
     }
  
};


class TagBaseTypeInfo{

  Identifier id;
  std::string desc;  
  size_t len;
public:
  TagBaseTypeInfo(Identifier id, 
                  int len, 
                  const std::string &desc = ""
  ):id(id),len((size_t)len),desc(desc){}
  TagBaseTypeInfo(Identifier id, 
                  size_t len, 
                  const std::string &desc = ""
                  ):id(id),len(len),desc(desc){}
  const Identifier & getName() const{
    return id;
  }
  size_t getLength() const{
    return len;
  }
  bool operator == (const Identifier &rhs) const{
    return id == rhs;
  }
  const std::string & getDescription() const{
    return desc;
  }
  
  void setDescription(const std::string &str){
    this->desc = str;
  }
};
typedef std::deque<TagBaseTypeInfo> TagBaseTypeInfoList;


class TagSystem : public FileHandler{
  
  
  class TagBaseTypeInfoMatcher{
    const Identifier &id;
  public:
    
    TagBaseTypeInfoMatcher(const Identifier &id):id(id){}    
    bool operator() (const TagBaseTypeInfo &item) const{
      return id == item.getName();
    }
  };
  
    class PropertyInfoIdMatcher{
      const Identifier &id;
    public:
      PropertyInfoIdMatcher(const Identifier &id):id(id){}
      bool operator() (const PropertyInfo &pi) const{
        return id == pi.getName();
      }
    };
    
	PropertyInfoList lsPI;
    TagBaseTypeInfoList  lsTTI;
	/*! Name */
	std::string name;
	/*! Description */
	std::string desc;
protected:
    TagSystem():FileHandler(){
	  
	}
	TagSystem(std::string name, std::string desc = "") : FileHandler(),name(name),desc(desc) {
	  
	}
	bool setTagBaseTypeInfo(const TagBaseTypeInfo & tbti){
      if ( hasTagBaseTypeInfo(tbti) )
        return false;
      
      lsTTI.push_back(tbti);
      
      return true;
	}
	/*TagSystem & operator << (const TagBaseTypeInfo &p){
      setTagBaseTypeInfo(p);
      
      return * (static_cast<TagSystem*>(this) );
    }*/
	bool setPropertyInfo(const PropertyInfo &p){
      if ( hasPropertyInfo(p) )
        return false;
      
      lsPI.push_back(p);
      
      return true;
        
	}
	/*TagSystem & operator << (const PropertyInfo &p){
      setPropertyInfo(p);
      return *this;
	}*/
	void setName(const std::string & name){
	  this->name = name;
	}
	void setDescription(const std::string & desc){
	  this->desc = desc;
	}
	
public:
	const PropertyInfoList & getSupportedPropertyTypes() const{
	  return lsPI;
	}
	bool hasPropertyInfo(const Identifier &id) const{
      PropertyInfoIdMatcher piim(id);
      
      PropertyInfoList::const_iterator it = 
      std::find_if(lsPI.begin(),lsPI.end(),piim);
      
      return ( lsPI.end() != it );
    }
	bool hasPropertyInfo(const PropertyInfo &prop) const{
      PropertyInfoIdMatcher piim(prop.getName());
      
      PropertyInfoList::const_iterator it = 
      std::find_if(lsPI.begin(),lsPI.end(),piim);
      
      return ( lsPI.end() != it );
    }
	const PropertyInfo & isSupportedPropertyType(const Identifier &id) const{
	  
        PropertyInfoIdMatcher piim(id);
        
	    PropertyInfoList::const_iterator it = 
        std::find_if(lsPI.begin(),lsPI.end(),piim);
	    
	    if ( lsPI.end() != it )
	      return *it;
	    
	    throw Tg::Exceptions::E_ITEM_NOT_FOUND;
	}
	const TagBaseTypeInfoList & getSupportedTagTypes() const{
      return lsTTI;
    }
    const TagBaseTypeInfo& isSupportedTagType(const Identifier &id) const{
      TagBaseTypeInfoMatcher piim(id);
      
      TagBaseTypeInfoList::const_iterator it = 
      std::find_if(lsTTI.begin(),lsTTI.end(),piim);
      
      if ( lsTTI.end() != it )
        return *it;
      
      throw Tg::Exceptions::E_ITEM_NOT_FOUND;
    }
    const TagBaseTypeInfo& isSupportedTagType(const TagBaseTypeInfo &tbti)const
    {
      TagBaseTypeInfoMatcher piim(tbti.getName());
      
      TagBaseTypeInfoList::const_iterator it = 
      std::find_if(lsTTI.begin(),lsTTI.end(),piim);
      
      if ( lsTTI.end() != it )
        return *it;
      
      throw Tg::Exceptions::E_ITEM_NOT_FOUND;
    }
    bool hasTagBaseTypeInfo(const Identifier &id) const{
      TagBaseTypeInfoMatcher piim(id);
      
      TagBaseTypeInfoList::const_iterator it = 
      std::find_if(lsTTI.begin(),lsTTI.end(),piim);
      
      throw lsTTI.end() != it;
    }
    bool hasTagBaseTypeInfo(const TagBaseTypeInfo &tbti) const{
      TagBaseTypeInfoMatcher piim(tbti.getName());
      
      TagBaseTypeInfoList::const_iterator it = 
      std::find_if(lsTTI.begin(),lsTTI.end(),piim);
    
      throw lsTTI.end() != it;
    }
	const std::string & getName() const{
	  return name;
	}
	const std::string & getDescription() const{
	  return desc;
	}
	
	
	
        
    };
    
    
    void setStandardPropertiesAndTypes(TagSystem *sys){
      NOT_YET_IMPLEMENTED
    }
 }
}



#endif
