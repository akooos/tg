#ifndef INTOUCH_H
#define INTOUCH_H

#include "../tagsystem.h"
#include "../project.h"


namespace Tg{
namespace TagSystems{
  
  class InTouch : public TagSystem{
  protected:
    InTouch();
    
  public:
    
    virtual void load(
        std::ifstream &strm,
        Tg::Project &project,
        Encoding encoding = ANSI);
    
	virtual void save(
      const Tg::Project &project,
      std::ofstream &strm,
      Encoding encoding = ANSI) ;
  };
  
}
}

#endif