#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H


#include <vector>

template <class T>
class EventListener{
  /*kinda Java style*/
    std::vector<T> lsEL;    
    
    public:
       void addEventListener(T el){
         lsEL.push_back(el);
      }
      
      const std::vector<T> & getEventListeners() const{
         return lsEL;
      }
      
      void removeEventListener(size_t index){
         lsEL.erase(lsEL.begin()+index);
      }
};
#endif
