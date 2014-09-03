
set(double_conversion_headers
double_conversion/bignum.h
double_conversion/bignum-dtoa.h
double_conversion/cached-powers.h
double_conversion/diy-fp.h
double_conversion/double-conversion.h
double_conversion/fast-dtoa.h
double_conversion/ieee.h
double_conversion/utils.h
)
  
set(double_conversion_sources
double_conversion/bignum.cc
double_conversion/bignum-dtoa.cc
double_conversion/cached-powers.cc
double_conversion/diy-fp.cc
double_conversion/double-conversion.cc
double_conversion/fast-dtoa.cc
)

set(headers
format_float.hpp
format_helpers.hpp
format_integers.hpp
format_it.hpp
format_out.hpp
format_stl.hpp
stack_format.hpp
${double_conversion_headers}
)

set(sources
format_it.cpp
format_out.cpp
${double_conversion_sources}
${headers}
)

add_definitions(-std=c++11)

add_library(format_it ${sources})

#
# associates the list of headers with the library
# for the purposes of installation/import into other projects
set_target_properties(format_it
    PROPERTIES PUBLIC_HEADER "${headers}")

#
# install command to set up library install
# given the above PUBLIC_HEADER property set, this
# pulls along all the header files with the library.
install(TARGETS format_it
  EXPORT format_itLibraryDepends
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}/lib" COMPONENT shlib
  ARCHIVE DESTINATION "${INSTALL_LIB_DIR}/lib" COMPONENT lib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/include/format_it"
  COMPONENT dev)
