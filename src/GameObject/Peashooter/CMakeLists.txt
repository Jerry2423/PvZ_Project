cmake_minimum_required(VERSION 3.16)

add_library(
  Peashooter
  STATIC
  Peashooter.hpp
  Peashooter.cpp
)

target_link_libraries(
  GameObject
  Framework
  Peashooter
  Plant
  GameWorld
)

target_include_directories(
  Peashooter
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Plant
  ${CMAKE_SOURCE_DIR}/src/GameObject/Peashooter

)
