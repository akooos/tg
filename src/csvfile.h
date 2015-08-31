#ifndef CSVFILE_H
#define CSVFILE_H

class ifstream;
class vector;
class string;


#include "filereader.h"

class CSVFile : private FileReader{

  std::vector<char> fieldDelimiter;
  std::vector<char> lineDelimiter;
  
public:  

  enum FieldSeperator{Comma, Semicolon,Tab};
  enum LineSeperator{CR, LF,CRLF} ;
  
  
  CSVFile( const char * filename, CSVFile::FieldSeperator fs = Comma,
                CSVFile::LineSeperator ls = LF, unsigned buffer_capacity = 512);
  ~CSVFile();


   bool nextLine(std::vector<std::string> &line) ;


  
  void setFieldSeperator( FieldSeperator fs );
  void setLineSeperator ( LineSeperator ls  );

  
  
  
};

#endif
