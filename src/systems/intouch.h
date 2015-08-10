#ifndef INTOUCH_H
#define INTOUCH_H

#include "../tagsystem.h"

#include "values.h"
#include "../project.h"


namespace Tg{
namespace TagSystems{
  
  class InTouch : public TagSystem{
  protected:
    InTouch();
    
  public:
    
    virtual void load(
        const std::istream &strm,
        Tg::Project &project,
        Encoding encoding = ANSI);
    
	virtual void save(
      const Tg::Project &project,
      std::ostream &strm,
      Encoding encoding = ANSI) ;
  };
  
}
}

#endif