cmake_minimum_required(VERSION 3.16)

add_library(
  Attacker
  STATIC
  Attacker.hpp
  Attacker.cpp
)

target_link_libraries(
  Attacker
  Framework
  GameWorld
  GameObject
)

target_include_directories(
  Attacker
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Attacker
)
