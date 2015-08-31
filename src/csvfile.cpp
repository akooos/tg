#include "utils.h"

#include "csvfile.h"



CSVFile::CSVFile(const char * filename,CSVFile::FieldSeperator fs, CSVFile::LineSeperator ls, unsigned buffer_capacity):FileReader(filename,buffer_capacity){


  setFieldSeperator(fs);
  setLineSeperator(ls);

}

CSVFile::~CSVFile()
{
 ITT(__FUNCTION__);
}



bool CSVFile::nextLine(std::vector<std::string> &line)
{

    while ( readBuffer() ){
        line.clear();
        unsigned line_match_icount = 0;
        unsigned field_match_icount = 0;

        while( buffer_index < getReadLen() ){

            if ( buffer[buffer_index] == fieldDelimiter[field_match_icount] )
            {
                if ( field_match_icount == fieldDelimiter.size())
                    return true;

                ++field_match_icount;
                continue;
            } else
                    {
                    field_match_icount = 0;
            }

            if ( buffer[buffer_index] == lineDelimiter[line_match_icount] )
            {
                if ( line_match_icount == lineDelimiter.size())
                    return true;

                ++line_match_icount;
                continue;
            } else
                    {
                    line_match_icount = 0;
            }

            ++buffer_index;
        }

        return false;

    }


    return false;


    /*
    std::string result;

    std::streampos pos = 0;

    //typedef std::vector<char>::const_iterator _VecIterator;
    //char *buffer = new char[max_buffer_size+1];

    while( !(strm.eof() || strm.fail()) ){

        pos = strm.tellg();
        strm.read(buffer,max_buffer_size);
        std::streamsize read_len = strm.gcount();
        buffer[ read_len ] = '\0';
        std::cout << "Buffer loaded =[" << buffer << "]"<< std::endl;
        std::cout << "Read size " << (int)read_len << " B" << std::endl;
        size_t i = 0,j = 0;
        while( buffer[i] != '\0' ){
            for(j = 0 ; j < delimiter.size(); ++j){
                if ( buffer[i+j] != delimiter[j] )
                    break;
            }
            if ( j == delimiter.size() ){
                result.append(buffer,i);
                if (strm.tellg()== -1 ){
                    strm.clear();
                }

                std::streamoff offset =  pos + static_cast<long int>(i+delimiter.size());
                std::cout << "Seek pos by offset " << (int)  offset << std::endl;
                std::cout << "From tellg=" << strm.tellg() << std::endl;
                strm.seekg(offset,strm.beg) ;
                std::cout << "Changed to tellg=" << strm.tellg() << std::endl;
                delete[] buffer;
                return result;
            }
            ++i;
        }

        result.append(buffer);
    }

    delete[] buffer;
    return result;
*/
}

void CSVFile::setFieldSeperator(CSVFile::FieldSeperator fs)
{
    /*
     * set encoding specific pattern
    */
  switch(fs){

       case Comma:{
          fieldDelimiter = {','};
          break;
        }
        case Semicolon:{
            fieldDelimiter = {';'};
            break;
        }
       case Tab:{
            fieldDelimiter = {'\t'};
        }
        default:{

        }

  }

}

void CSVFile::setLineSeperator(CSVFile::LineSeperator ls)
{
    /*
     * set encoding specific pattern
    */
    switch(ls){

         case CR:{
            lineDelimiter = {'\r'};
            break;
          }
          case LF:{
            lineDelimiter = {'\n'};
            break;
          }
         case CRLF:{
            lineDelimiter = {'\r','\n'};
            break;
          }
          default:{
            lineDelimiter = {'\n'};
          }

    }

}


