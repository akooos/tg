#ifndef CSVFILE_H
#define CSVFILE_H

class ifstream;
class vector;
class map;

class CSVFile{ 
public:
  enum FieldSeperator{Comma, Semicolon,Tab};
  enum LineSeperator{CR, LF,CRLF} ;  
private:
  FieldSeperator fs;
  LineSeperator ls;
  std::ifstream &strm;
  
  
  const char s8_CR           = {0x0C};
  const char s8_LF            = {0x0A};
  const char s8_CRLF[2]   = {0x0C,0x0A};
  char *fieldPatter;
  char *linePatter;
  
public:  
  
  
  
  CSVFile( std::ifstream & strm, 
                CSVFile::FieldSeperator fs = Comma, 
                CSVFile::LineSeperator ls = LF);
  
  inline std::vector<std::string> getCells();
  
  void setFieldSeperator( FieldSeperator fs );
  void setLineSeperator ( LineSeperator ls  );
  
  
  
};

#endif
