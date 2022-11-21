cmake_minimum_required(VERSION 3.14)
project(videoGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp mainMenu.cpp mainMenu.h Application.cpp Application.h Components.cpp Components.h EventHandler.cpp EventHandler.h Updater.cpp Updater.h Player.cpp Player.h Animation.cpp Animation.h ResourceHolder.cpp ResourceHolder.h Entity.cpp Entity.h Mommy.cpp Mommy.h ResourceIdentifier.h Game.cpp Game.h playerType.h)
add_executable(videoGame ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(videoGame sfml-system sfml-window sfml-graphics sfml-audio sfml-network)