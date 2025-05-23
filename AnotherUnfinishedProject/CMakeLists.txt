message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
message(STATUS "CMAKE_GENERATOR: ${CMAKE_GENERATOR}")
message(STATUS "CMAKE_GENERATOR_PLATFORM: ${CMAKE_GENERATOR_PLATFORM}")
message(STATUS "CMAKE_SYSTEM_PROCESSOR: ${CMAKE_SYSTEM_PROCESSOR}")


# Define minimum required CMake version
cmake_minimum_required(VERSION 4.0.2)

# Setting project name
project(AnotherUnfinishedProject)

# Setting target architecture
set(CMAKE_GENERATOR_PLATFORM Win32)
message(STATUS "Target platform: ${CMAKE_GENERATOR_PLATFORM}")

# setting c++ required version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# setting environmental variable as SFML_DIR for easier usage inside this file
set(SFML_DIR "$ENV{SFML_ROOT_32bit}")

# Project start location file 
add_executable (AnotherUnfinishedProject 
"src/Main.cpp"
"src/AnimationState.cpp"

"src/Entities/HitBox.cpp"
"src/Entities/Mobs/Orc.cpp"
"src/Entities/Player/Player.cpp"

"src/Helpers/Loader.cpp"
"src/Helpers/Math.cpp"

"src/Managers/EnemyManager.cpp"
)

# including header files so Compiler would not cry over non existant classes
target_include_directories(AnotherUnfinishedProject PUBLIC "${SFML_DIR}/include")

# message example when running CMake build command
message(STATUS "SFML_DIR from env: ${SFML_DIR}/include/SFML")

# linking STATIC libraries folder
target_link_directories(AnotherUnfinishedProject PUBLIC "${SFML_DIR}/lib")

# defining STATIC libraries usage as default
add_definitions(-DSFML_STATIC)

# linking actual STATIC libraries
target_link_libraries(AnotherUnfinishedProject PRIVATE
    debug sfml-system-s-d
    debug sfml-graphics-s-d
    debug sfml-window-s-d
    debug sfml-network-s-d

    optimized sfml-system-s
    optimized sfml-graphics-s
    optimized sfml-window-s
    optimized sfml-network-s

    debug opengl32
    debug freetype
    debug winmm
    debug gdi32
    debug ws2_32
)

