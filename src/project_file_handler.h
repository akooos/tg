#ifndef PROJECT_FILE_HANDLER
#define PROJECT_FILE_HANDLER

#include "../include/csingleton.h"

class istream;
class ostream;
class Project;

namespace Tg{

  struct FileHandler : public CSingleton<FileHandler> {
    
      enum Encoding { ANSI,
#ifdef USING_UNICODE
		      UTF8, 
		      UTF8BOM, 
		      UCS2, 
		      UTF16, 
		      UTF16BOMLE, 
		      UT16BOMBE
      };
#else
      };
#endif
  
	friend class CSingleton<FileHandler>; 
	virtual void load(const std::istream &strm, Project &project, Encoding encoding = ANSI) = 0;
	virtual void save(const Project &project, std::ostream &strm, Encoding encoding = ANSI)  = 0;
	
protected:
    FileHandler(){}
  };
}
#endif
