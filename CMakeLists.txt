set(CMAKE_EXE_LINKER_FLAGS "-static")
cmake_minimum_required(VERSION 3.14)
project(RandomBattler)

set(CMAKE_CXX_STANDARD 17)

add_executable(RandomBattler src/Main.cpp
        src/TestScriptRunner.cpp
        src/TestScriptRunner.h
        src/HeroTemplate.cpp
        src/HeroTemplate.h
        src/Actions.cpp
        src/Actions.h)

include_directories(include)

target_link_libraries(RandomBattler ${CMAKE_CURRENT_SOURCE_DIR}/libs/lua54.lib)





#if(WIN32)
#    target_link_libraries(luatests ${CMAKE_CURRENT_SOURCE_DIR}/../libs/lua54.lib)
#endif()
#if(APPLE)
#    target_link_libraries(luatests ${CMAKE_CURRENT_SOURCE_DIR}/../libs/lua54..a)
#endif()