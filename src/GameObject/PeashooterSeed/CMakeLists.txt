cmake_minimum_required(VERSION 3.16)

add_library(
  PeashooterSeed
  STATIC
  PeashooterSeed.hpp
  PeashooterSeed.cpp
)

target_link_libraries(
  PeashooterSeed
  Framework
  GameWorld
  Seed
  GameObject
)

target_include_directories(
  PeashooterSeed
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Seed
  ${CMAKE_SOURCE_DIR}/src/GameObject/PeashooterSeed

)
