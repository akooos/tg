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
  
  
  const char s8_CR[1]      = {'\r'};
  const char s8_LF[1]      = {'\n'};
  const char s8_CRLF[2]  = {'\r','\n'};
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
