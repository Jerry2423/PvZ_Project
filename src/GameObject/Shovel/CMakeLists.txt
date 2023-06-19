cmake_minimum_required(VERSION 3.16)

add_library(
  Shovel
  STATIC
  Shovel.hpp
  Shovel.cpp
)

target_link_libraries(
  GameObject
  Framework
  Shovel
  GameWorld
)

target_include_directories(
  Shovel
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Shovel
)
