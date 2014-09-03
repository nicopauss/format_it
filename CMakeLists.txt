cmake_minimum_required(VERSION 2.8)
project(FormatIt)

# set paths for install -- empty initially
# Offer the user the choice of overriding the installation directories
set(INSTALL_BIN_DIR CACHE PATH "Installation directory for libraries")
set(INSTALL_LIB_DIR CACHE PATH "Installation directory for libraries")
set(INSTALL_INCLUDE_DIR CACHE PATH "Installation directory for include")
# set suffix for CMake files used for packaging
if(WIN32 AND NOT CYGWIN)
  set(INSTALL_CMAKE_DIR CMake)
else()
  set(INSTALL_CMAKE_DIR lib/CMake/double-conversion)
endif()

# Make relative paths absolute (needed later)
foreach(p LIB BIN INCLUDE CMAKE)
  set(var INSTALL_${p}_DIR)
  if(NOT IS_ABSOLUTE "${${var}}")
    set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
  endif()
endforeach()


add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(example)
