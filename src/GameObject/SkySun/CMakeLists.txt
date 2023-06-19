cmake_minimum_required(VERSION 3.16)

add_library(
  SkySun
  STATIC
  SkySun.hpp
  SkySun.cpp
)

target_link_libraries(
  GameObject
  Framework
  Sun
  SkySun
)

target_include_directories(
  SkySun
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameObject/SkySun
  ${CMAKE_SOURCE_DIR}/src/GameObject/Sun

)
