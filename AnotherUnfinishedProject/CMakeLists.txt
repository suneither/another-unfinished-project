cmake_minimum_required(VERSION 4.0.2)
project(AnotherUnfinishedProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Path to SFML (64-bit version!)
set(SFML_ROOT $ENV{SFML_ROOT_x64})
set(SFML_INCLUDE_DIR "${SFML_ROOT}/include")
set(SFML_LIB_DIR "${SFML_ROOT}/lib")

# Source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Include + link manually
target_include_directories(${PROJECT_NAME} PUBLIC ${SFML_INCLUDE_DIR})
link_directories(${SFML_LIB_DIR})

# Define static linking
target_compile_definitions(${PROJECT_NAME} PUBLIC SFML_STATIC)

# Link SFML libs manually (in the right order)
target_link_libraries(${PROJECT_NAME}
    sfml-graphics-s
    sfml-window-s
    sfml-system-s
)

# Optional: multithreaded static runtime (if you want to ditch DLLs altogether)
# set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
