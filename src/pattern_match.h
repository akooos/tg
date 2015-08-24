#ifndef PATTERN_MATCH
#define PATTERN_MATCH
#include <iterator>

#include <iostream>
    template <
    class ValueType,
    class IteratorType,
    class  PatternContainer = std::vector<ValueType>
                    >
     class  LinearPatternMatch{
         const PatternContainer & pattern;
     public:
         LinearPatternMatch(const PatternContainer & pattern):pattern(pattern){}
         IteratorType match(
               const IteratorType        &it_begin,
               const IteratorType        &it_end_org)
         {
             typename PatternContainer::const_iterator  it_ptrn;
             IteratorType it_end = it_end_org;
            // int p_len = -1*pattern.size();
            // std::advance (it_end ,p_len);

             for( IteratorType it = it_begin;
                    it_begin != it_end;
                    ++it)
             {
               for(  it_ptrn = pattern.begin();
                        it_ptrn !=  pattern.end();
                       ++it_ptrn)
                {
                    if ( *it  !=  *it_ptrn )
                           break;
                    ++it;
                    std::cout << "became" << *it << std::endl;

                 }

                 if ( it_ptrn == pattern.end() )
                   return it;
             }
            return it_end;
        }
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