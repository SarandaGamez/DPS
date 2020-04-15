cmake_minimum_required (VERSION 2.8.12)

# add c++11 standard to compiler
add_compile_options(-std=c++11)

project(DPS)

set(BINDIR ${PROJECT_BINARY_DIR})
set(SRCDIR ${PROJECT_SOURCE_DIR})

set(GAME_TITLE "Department of People's Safety")
set(GAME_VERSION_MAJOR 0)
set(GAME_VERSION_MINOR 1)
set(GAME_VERSION_RELEASE pre-alpha)


configure_file(
	"${SRCDIR}/config.h.in"
	"${BINDIR}/config.h"
)
include_directories("${BINDIR}")

file(GLOB_RECURSE SRC_FILES
    GLOB_CPP_PATTERNS src/*.cpp 
    GLOB_H_PATTERNS include/*.h RECURSE_GROUP
)

set(EXE_NAME "DPS")
add_executable(${EXE_NAME} ${SRC_FILES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${SFML_DIR}/include)


if(WIN32 OR MINGW OR MSVC)
add_subdirectory("${PROJECT_SOURCE_DIR}/ext/sfml")

# link with SFML library dependiences
target_link_libraries(${EXE_NAME} sfml-system sfml-window sfml-graphics sfml-audio)

endif(WIN32 OR MINGW OR MSVC)



if(UNIX)

#SFML
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
    target_link_libraries(${EXE_NAME} sfml-system sfml-window sfml-graphics sfml-audio)
endif()

endif(UNIX)
