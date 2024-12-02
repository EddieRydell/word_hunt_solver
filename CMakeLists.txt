cmake_minimum_required(VERSION 3.28)
project(WordHuntSolver)

set(CMAKE_CXX_STANDARD 17)

#set(OpenCV_DIR "C:\\Users\\eddie\\opencv-4.10.0\\opencv-4.10.0\\cmake")

# Find OpenCV
#find_package(OpenCV REQUIRED)

# Add your executable
add_executable(WordHuntSolver main.cpp
        trie.h)

# Link OpenCV libraries
target_link_libraries(WordHuntSolver PRIVATE ${OpenCV_LIBS})

# Include OpenCV headers
#target_include_directories(WordHuntSolver PRIVATE ${OpenCV_INCLUDE_DIRS})

# Print OpenCV version (optional, for debugging purposes)
#message(STATUS "OpenCV version: ${OpenCV_VERSION}")
#message(STATUS "OpenCV include directories: ${OpenCV_INCLUDE_DIRS}")
#message(STATUS "OpenCV libraries: ${OpenCV_LIBS}")
