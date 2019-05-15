project(BangGraphics C CXX)
cmake_minimum_required(VERSION 3.7)
set (CMAKE_CXX_STANDARD 11)

if (NOT TARGET BangMath)
    add_subdirectory(BangMath)
endif ()

if (NOT TARGET BangCore)
    add_subdirectory(BangCore)
endif ()

set(BANG_GRAPHICS_SOURCE_DIR "src")
set(BANG_GRAPHICS_INCLUDE_DIR "include")
set(BANG_GRAPHICS_INCLUDE_FULL_DIR "${BANG_GRAPHICS_INCLUDE_DIR}/BangGraphics")
file(GLOB_RECURSE BANG_GRAPHICS_HEADER_FILES "${BANG_GRAPHICS_INCLUDE_FULL_DIR}/*.h" "${BANG_GRAPHICS_INCLUDE_FULL_DIR}/*.tcc")
file(GLOB_RECURSE BANG_GRAPHICS_SRC_FILES "${BANG_GRAPHICS_SOURCE_DIR}/*.cpp")

add_library(BangGraphics ${BANG_GRAPHICS_SRC_FILES})
set_target_properties(BangGraphics PROPERTIES LINKER_LANGUAGE CXX)
target_sources(BangGraphics PUBLIC ${BANG_GRAPHICS_HEADER_FILES})
target_include_directories(BangGraphics PUBLIC "${BANG_GRAPHICS_INCLUDE_DIR}/")
target_link_libraries(BangGraphics PUBLIC BangMath BangCore)
