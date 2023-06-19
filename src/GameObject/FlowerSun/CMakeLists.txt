cmake_minimum_required(VERSION 3.16)

add_library(
  FlowerSun
  STATIC
  FlowerSun.hpp
  FlowerSun.cpp
)

target_link_libraries(
  GameObject
  Framework
  Sun
  FlowerSun
)

target_include_directories(
  FlowerSun
  PUBLIC 
  ${CMAKE_SOURCE_DIR}/src/
  ${CMAKE_SOURCE_DIR}/src/Framework/
  ${CMAKE_SOURCE_DIR}/src/GameWorld/
  ${CMAKE_SOURCE_DIR}/src/GameObject/
  ${CMAKE_SOURCE_DIR}/src/GameObject/FlowerSun
  ${CMAKE_SOURCE_DIR}/src/GameObject/Sun

)
