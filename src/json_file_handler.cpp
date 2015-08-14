#include "json_file_handler.h"

#include <iostream>
#include "project.h"

#include "../3rdparty/minijson_writer/minijson_writer.hpp"
#include "../3rdparty/minijson_reader/minijson_reader.hpp"


 Tg::JSON_FileHandler::JSON_FileHandler():FileHandler(){
   NOT_YET_IMPLEMENTED
 }
 void Tg::JSON_FileHandler::load(const std::ifstream &strm,
                                                  Project &project, 
                                                  Encoding encoding = ANSI)
 {
   NOT_YET_IMPLEMENTED
 }
 void Tg::JSON_FileHandler::save(const Project &project, 
                                                  std::ofstream &str, 
                                                  Encoding encoding = ANSI)
 {
   NOT_YET_IMPLEMENTED
 }
 
