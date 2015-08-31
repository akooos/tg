#include "filereader.h"


FileReader::FileReader(const char* filename,unsigned buffer_capacity):buffer_capacity(buffer_capacity)
{
    assert( buffer_capacity > 0 );
    strm = new std::ifstream(filename);
    buffer = new char[buffer_capacity];
}

FileReader::~FileReader()
{
    delete strm;
    delete[] buffer;
     ITT(__FUNCTION__);
}

bool FileReader::readBuffer()
{
    if ( ( getReadLen() > buffer_index )  ||  ( !strm->eof() && !strm->fail() && strm->read(buffer,buffer_capacity) ) ){

        buffer_index = 0;
        return true;
    }

    return false;
}

unsigned FileReader::getReadLen() const
{

  return strm->gcount();

}

