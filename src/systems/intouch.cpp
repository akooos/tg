#include "intouch.h"

Tg::TagSystems::InTouch::InTouch() : Tg::TagSystems::TagSystem("InTouch")
{
  
  //Tg::TagSystems::setStandardPropertiesAndTypes(this);
  
  setTagBaseTypeInfo( TagBaseTypeInfo("IOAccess", 0) );
  setTagBaseTypeInfo( TagBaseTypeInfo("IOReal",4));
  setTagBaseTypeInfo( TagBaseTypeInfo("IOInteger",4));
  setTagBaseTypeInfo( TagBaseTypeInfo("IODiscrete",1));
  setTagBaseTypeInfo( TagBaseTypeInfo("IOMessage",0));
  setTagBaseTypeInfo( TagBaseTypeInfo("MemoryReal",4));
  setTagBaseTypeInfo( TagBaseTypeInfo("MemoryInteger",4));
  setTagBaseTypeInfo( TagBaseTypeInfo("MemoryDiscrete",1));
  setTagBaseTypeInfo( TagBaseTypeInfo("MemoryMessage",0));
  setTagBaseTypeInfo( TagBaseTypeInfo("AlarmGroup",0));
  setTagBaseTypeInfo( TagBaseTypeInfo("IndirectDiscrete",1));
  setTagBaseTypeInfo( TagBaseTypeInfo("IndirectAnalog",4));
  setTagBaseTypeInfo( TagBaseTypeInfo("IndirectInteger",4));
  setTagBaseTypeInfo( TagBaseTypeInfo("HistTrend",4));
  setTagBaseTypeInfo( TagBaseTypeInfo("TagId",4));
  
  setPropertyInfo( PropertyInfo("mode",
							Tg::TagSystems::Enum,
							{ 	StdStrValue("ask"), 
								StdStrValue("replace"),
								StdStrValue("update"),
								StdStrValue("ignore"),
								StdStrValue("terminate"),
								StdStrValue("test"),
							},
							{"Project"}
						   ));
  
}
void Tg::TagSystems::InTouch::load ( 
			  const std::istream& strm, 
			  Tg::Project&	project,
			  Tg::FileHandler::Encoding encoding )
{
  NOT_YET_IMPLEMENTED
}
void Tg::TagSystems::InTouch::save ( 
		const Tg::Project& project, 
		std::ostream& strm, 
		Tg::FileHandler::Encoding encoding )
{
  NOT_YET_IMPLEMENTED
}

