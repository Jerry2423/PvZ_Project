cmake_minimum_required(VERSION 3.16)

add_library(
  Plant
  STATIC
  Plant.hpp
  Plant.cpp
)

target_link_libraries(
  GameObject
  Framework
  Plant
  GameWorld
)

target_include_directories(
  Plant
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Plant
)
