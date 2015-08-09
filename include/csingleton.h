#ifndef CSINGLETON_H
#define CSINGLETON_H
// definition of singleton
template <class T>
class CSingleton
{
        static T *i;
    protected:
        CSingleton(){}
    public:
        static T * instance()
        {
            return i == 0 ? i = new T : i;
        }
        static void destruct()
        {
           if ( i )
           {
                delete i;
                i = 0;
           }
        }
};

template <class T> T* CSingleton<T>::i = 0;
// ----------------------------------------------------

#endif // CSINGLETON_H