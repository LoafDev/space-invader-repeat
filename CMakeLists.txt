cmake_minimum_required(VERSION 3.10)
project(Space_Invader_Repeat C)

set(CMAKE_C_STANDARD 99)

include_directories(src/include)

set(SOURCES
  src/game.c
  src/player.c
)

add_executable(game ${SOURCES})
target_link_libraries(game raylib)
