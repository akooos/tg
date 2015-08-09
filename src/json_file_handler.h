#ifndef JSON_FILE_HANDLER
#define JSON_FILE_HANDLER

#include "project_file_handler.h"

namespace Tg{
  
struct JSON_FileHandler : public FileHandler {
  
   virtual void load(const std::istream &strm, Project &project, Encoding encoding = ANSI);
   virtual void save(const Project &project, std::ostream &strm, Encoding encoding = ANSI);
protected:
    JSON_FileHandler();

};

}

#define JSON_FH Tg::JSON_FileHandler::instance()

#endif
