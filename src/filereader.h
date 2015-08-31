#ifndef FILEREADER_H
#define FILEREADER_H

#include "utils.h"

class FileReader
{

    std::ifstream *strm;

  protected:
    char * buffer;
    const unsigned buffer_capacity;
    unsigned buffer_index;

public:
    FileReader(const char* filename,unsigned buffer_capacity = 4096);
    ~FileReader();

    bool readBuffer();

    unsigned getReadLen() const;
};

#endif // FILEREADER_H
