#ifndef PROJECT_FILE_HANDLER
#define PROJECT_FILE_HANDLER


#include "project.h"
#include "csingleton.h"

namespace Tg{

class FileHandlerComponent{
    
    protected:
        std::string name;
    public:
        FileHandlerComponent(const std::string &name):name(name){}
    virtual void load( Project &project ) = 0;
    virtual void save( const Project &project ) = 0;

};

class ProjectFileHandler : public CSingleton<ProjectFileHandler>{

    friend class CSingleton<ProjectFileHandler>;

    std::set<FileHandlerComponent> fhs;
    ProjectFileHandler(){ }

    public:
      void add(FileHandlerComponent *fh){
          fhs.push_back(fh);
      }

};

#define PFH ProjectFileHandler::instance()

}
#endif
