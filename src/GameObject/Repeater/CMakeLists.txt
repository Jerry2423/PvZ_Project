cmake_minimum_required(VERSION 3.16)

add_library(
  Repeater
  STATIC
  Repeater.hpp
  Repeater.cpp
)

target_link_libraries(
  GameObject
  Framework
  Repeater
  Plant
  GameWorld
  Peashooter
)

target_include_directories(
  Repeater
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Plant
  ${CMAKE_SOURCE_DIR}/src/GameObject/Repeater
  ${CMAKE_SOURCE_DIR}/src/GameObject/Peashooter

)
