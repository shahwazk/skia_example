cmake_minimum_required(VERSION 3.8)
project(skia_example)

# To build skia_example with c++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Disable shadowing warnings
add_compile_options(-Wno-shadow)

add_executable(skia_example
  src/main.cpp
)

# Set Skia directory
set(SKIA_DIR ${CMAKE_SOURCE_DIR}/../skia_setup/skia)

# find freetype2 and harfbuzz package
find_package(PkgConfig REQUIRED)
pkg_check_modules(PC_FREETYPE REQUIRED freetype2)
pkg_check_modules(PC_HARFBUZZ REQUIRED harfbuzz)

target_include_directories(skia_example PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
  ${SKIA_DIR}
)

target_link_libraries(skia_example
  ${SKIA_DIR}/out/Release-clang/libskia.a
  ${SKIA_DIR}/out/Release-clang/libskshaper.a
  ${SKIA_DIR}/out/Release-clang/libsvg.a
  ${SKIA_DIR}/out/Release-clang/libskparagraph.a
)

target_link_libraries(skia_example
  ${PC_FREETYPE_LIBRARIES}
  ${PC_HARFBUZZ_LIBRARIES}
  GL
  GLU
  X11
  pthread
  dl
  m
  c++
  c++abi
)

install(
  TARGETS
  skia_example
  EXPORT ${PROJECT_NAME}Targets
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
  INCLUDES DESTINATION include
)

install(DIRECTORY include/
  DESTINATION include
)
