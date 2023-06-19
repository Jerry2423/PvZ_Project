cmake_minimum_required(VERSION 3.16)

add_library(
  RepeaterSeed
  STATIC
  RepeaterSeed.hpp
  RepeaterSeed.cpp
)

target_link_libraries(
  RepeaterSeed
  Framework
  GameWorld
  Seed
  GameObject
)

target_include_directories(
  RepeaterSeed
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Seed
  ${CMAKE_SOURCE_DIR}/src/GameObject/RepeaterSeed

)
