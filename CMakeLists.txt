cmake_minimum_required(VERSION 3.16)
project(lag-fix-suite CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lagfixsuite
    src/main.cpp
    src/routes.cpp
    src/tweaks.cpp
    src/monitor.cpp
    src/cli.cpp
)

target_include_directories(lagfixsuite PRIVATE include)

if(WIN32)
    target_link_libraries(lagfixsuite PRIVATE userenv)
endif()
