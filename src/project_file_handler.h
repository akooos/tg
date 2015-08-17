﻿#ifndef PROJECT_FILE_HANDLER
#define PROJECT_FILE_HANDLER

class ifstream;
class ofstream;
class Project;

namespace Tg{

  struct FileHandler  {

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

	virtual void load(std::ifstream &strm,
                               Project &project,
                               Encoding encoding = ANSI
                              ) = 0;

	virtual void save(const Project &project,
                                std::ofstream &strm,
                                Encoding encoding = ANSI
                              )  = 0;

protected:
    FileHandler(){}
  };


}
#endif
