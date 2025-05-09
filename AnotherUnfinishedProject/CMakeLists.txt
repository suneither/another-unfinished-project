cmake_minimum_required(VERSION 3.16)
project(TinyDungeon VERSION 0.1 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define SFML_STATIC preprocessor macro
add_definitions(-DSFML_STATIC)

# Set path to SFML manually if it's not globally installed
# Example: set(SFML_ROOT "C:/Libraries/SFML")
# Or rely on environment variable or default path

# Look for SFML
set(SFML_DIR "C:/SFML/lib/cmake/SFML")  # ?? adjust this path to YOUR SFML cmake module folder
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

# Add your source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(TinyDungeon ${SOURCES})

# Include directories (if SFML is not globally known)
target_include_directories(TinyDungeon PRIVATE "C:/SFML/include")  # ?? adjust

# Link SFML
target_link_libraries(TinyDungeon PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

# Optional: Post-build copy of needed SFML DLLs (if you're dynamically linking)
# Not needed for static linking, but useful for dynamic setups

