cmake_minimum_required(VERSION 3.10)

project(optical_illusion VERSION 1.0)

# Set default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Build type flags
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -fstack-protector-all")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -fdelete-null-pointer-checks")

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(optical_illusion src/main.cpp)
target_link_libraries(optical_illusion sfml-graphics sfml-window)

# Warning flags
target_compile_options(optical_illusion PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wformat-security -Wundef -Wconversion -Wpedantic -Wformat=2>
)
