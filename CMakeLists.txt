cmake_minimum_required(VERSION 3.14)
project(game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp animation.cpp animation.h Player.cpp Player.h Collider.cpp Collider.h Platform.cpp Platform.h level1.cpp global.h view.cpp Events.cpp Events.h onCollision.cpp Level.cpp Level.h levelTest.cpp)
add_executable(game ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(game sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
