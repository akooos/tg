add_executable (tg main.cpp converters.h utils.h csvfile.cpp           
systems/intouch.cpp)
target_link_libraries( tg ${LIBS} )
