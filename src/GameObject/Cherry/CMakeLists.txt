cmake_minimum_required(VERSION 3.16)

add_library(
  Cherry
  STATIC
  Cherry.hpp
  Cherry.cpp
)

target_link_libraries(
  GameObject
  Framework
  Cherry
  Plant
  GameWorld
)

target_include_directories(
  Cherry
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Plant
  ${CMAKE_SOURCE_DIR}/src/GameObject/Cherry

)
