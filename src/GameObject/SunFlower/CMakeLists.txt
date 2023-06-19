cmake_minimum_required(VERSION 3.16)

add_library(
  SunFlower
  STATIC
  SunFlower.hpp
  SunFlower.cpp
)

target_link_libraries(
  GameObject
  Framework
  SunFlower
  Plant
  GameWorld
)

target_include_directories(
  SunFlower
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Plant
  ${CMAKE_SOURCE_DIR}/src/GameObject/SunFlower

)
