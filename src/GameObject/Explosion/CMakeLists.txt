cmake_minimum_required(VERSION 3.16)

add_library(
  Explosion
  STATIC
  Explosion.hpp
  Explosion.cpp
)

target_link_libraries(
  Explosion
  GameObject
  Framework
  Attacker
)

target_include_directories(
  Explosion
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Explosion
  ${CMAKE_SOURCE_DIR}/src/GameObject/Attacker
)
