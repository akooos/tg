#ifndef PATTERN_MATCH
#define PATTERN_MATCH

#include "../include/defs.h"

    template<typename IteratorType>
     class  LinearPatternMatch{
         const IteratorType & it_ptrn_begin;
         const IteratorType & it_ptrn_end;
     public:
       
      LinearPatternMatch(const IteratorType & it_ptrn_begin,
                                    const IteratorType & it_ptrn_end
        ):it_ptrn_begin(it_ptrn_begin),it_ptrn_end(it_ptrn_end){}


       IteratorType match(
              const IteratorType &it_begin,
              const IteratorType &it_end
         ){

            typedef typename std::iterator_traits<IteratorType>::iterator_category category;
            return match(it_begin,it_end,category());
      }

        const std::random_access_iterator_tag        & match(
          const std::random_access_iterator_tag        &it_begin,
          const std::random_access_iterator_tag        &it_end,
          std::random_access_iterator_tag)
        {
          /*
           int ptrn_len = it_ptrn_end - it_ptrn_begin;
           const std::random_access_iterator_tag  it_end_chopped = it_end;
           if (  ( it_end - it_begin ) < ptrn_len  ){
            ITT(" it_end_org returning");
            return it_end;
          }

          std::advance (it_end_chopped ,-ptrn_len);
          
          for(const std::random_access_iterator_tag  it =it_begin; it != it_end_chopped;++it)
          {
            ITT(*it);
            const std::random_access_iterator_tag it_sub = it;
            std::random_access_iterator_tag it_ptrn = it_ptrn_begin;
            for( ;
                it_ptrn !=  it_ptrn_end && it_sub != it_end;
                ++it_ptrn)
            {

                  if ( *it_sub !=  (*it_ptrn) )
                      break;

                  ++it_sub;
            }
     
              if ( it_ptrn == it_ptrn_end ){

                  ITT("Returning IT");
                  return it;
               }

           }
*/
             ITT("Returning END");
             return it_end;
     }
        
       /*  LinearPatternMatch(const PatternContainer & 
pattern):pattern(pattern){}
         IteratorType match(
               const IteratorType        &it_begin,
               const IteratorType        &it_end_org)
         {
             typename PatternContainer::const_iterator  it_ptrn;
             IteratorType it_end = it_end_org;
             int ptrn_len = -pattern.size();
             std::advance (it_end ,ptrn_len);

             for( IteratorType it = it_begin;
                    it_begin != it_end;
                    ++it)
             {
               for(  it_ptrn = pattern.begin();
                        it_ptrn !=  pattern.end();
                       ++it_ptrn)
                {
                   std::cout << *it << std::endl;
                   std::cout << *it_ptrn << std::endl;
                    if ( *it  !=  (*it_ptrn) )
                           break;
                    ++it;

                 }

                 if ( it_ptrn == pattern.end() )
                   return it;
             }
            return it_end;
        }*/
    };
/*
    template <
        class ValueType,
        class IteratorType,
        class  PatternContainer = std::vector<ValueType>
                    >
        struct  KMPPatternMatch{

            IteratorType match(
                 const IteratorType &it_begin,
                 const IteratorType &it_end,
                 const  PatternContainer  &pattern)
            {

            return it_end;
        }
    };*/

#endif
