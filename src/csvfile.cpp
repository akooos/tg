#include <fstream>
#include <vector>

#include "csvfile.h"

CSVFile::CSVFile( std::ifstream & strm, 
                           CSVFile::FieldSeperator fs ,
                           CSVFile::LineSeperator ls 
                          ):strm(strm),fs(fs){
  
} 



std::vector< std::string > CSVFile::getCells()
{    
 }
