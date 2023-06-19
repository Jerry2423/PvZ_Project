cmake_minimum_required(VERSION 3.16)

add_library(
  BuckZombie
  STATIC
  BuckZombie.hpp
  BuckZombie.cpp
)

target_link_libraries(
  BuckZombie
  GameObject
  Framework
  Zombie
  GameWorld
)

target_include_directories(
  BuckZombie
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Zombie
  ${CMAKE_SOURCE_DIR}/src/GameObject/BuckZombie

)
