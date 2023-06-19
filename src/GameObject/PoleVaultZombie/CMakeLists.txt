cmake_minimum_required(VERSION 3.16)

add_library(
  PoleVaultZombie
  STATIC
  PoleVaultZombie.hpp
  PoleVaultZombie.cpp
)

target_link_libraries(
  PoleVaultZombie
  GameObject
  Framework
  Zombie
  GameWorld
)

target_include_directories(
  PoleVaultZombie
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameObject/Zombie
  ${CMAKE_SOURCE_DIR}/src/GameObject/PoleVaultZombie

)
