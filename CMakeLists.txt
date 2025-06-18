cmake_minimum_required(VERSION 3.10)
project(Space_Invader_Repeat C)

set(CMAKE_C_STANDARD 99)

include_directories(src/include)
if(WIN32)
    include_directories("C:/raylib/include")
    link_directories("C:/raylib/lib")
endif()

set(SOURCES
  src/game.c
  src/snake.c
  src/apple.c
)

add_executable(game ${SOURCES})
target_link_libraries(game raylib winmm)
