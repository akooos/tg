﻿#ifndef JSON_FILE_HANDLER
#define JSON_FILE_HANDLER

#include "project_file_handler.h"

namespace Tg{
  
struct JSON_FileHandler : public FileHandler {
  
   virtual void load(std::ifstream &strm,
                              Project &project, 
                              Encoding encoding = ANSI
                            );
   virtual void save(const Project &project, 
                              std::ofstream &strm, 
                              Encoding encoding = ANSI
                    );
protected:
    JSON_FileHandler();

};

}

#endif
