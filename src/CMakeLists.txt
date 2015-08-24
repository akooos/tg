add_executable (tg main.cpp converters.h utils.h csvfile.cpp
systems/intouch.cpp pattern_match.h ../include/defs.h)
target_link_libraries( tg ${LIBS} )
