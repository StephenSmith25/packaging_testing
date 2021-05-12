cmake_minimum_required(VERSION 3.16)

project(packaging_test)

set(CMAKE_CXX_STANDARD 17)

# Include Conan Packages
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)



set(THREADING_LINK_LIBS ${THREADING_LINK_LIBS} CONAN_PKG::tbb)

if(APPLE)
set(THREADING_LINK_LIBS ${THREADING_LINK_LIBS} CONAN_PKG::onedpl)
endif(APPLE)

add_subdirectory(src)

