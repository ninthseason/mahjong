cmake_minimum_required(VERSION 3.28)
project(mahjong)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Mahjong
                    ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty
                    ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/pybind11
                    ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/fmt/include
                    ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/tenhou
                    ${CMAKE_CURRENT_SOURCE_DIR}
                    )

set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_BINARY_DIR}/lib)

set(CMAKE_CXX_STANDARD 14)

if (UNIX)
    add_definitions("-fPIC")
endif()

find_package (Python3 COMPONENTS Interpreter Development)
message(use\ python\ interpreter: ${PYTHON_INCLUDE_DIRS})
include_directories(${PYTHON_INCLUDE_DIRS})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resource/syanten.dat ${CMAKE_CURRENT_BINARY_DIR}/resource/syanten.dat COPYONLY)

add_subdirectory(ThirdParty EXCLUDE_FROM_ALL)
add_subdirectory(Mahjong)
add_subdirectory(Pybinder)
add_subdirectory(test)
add_subdirectory(demo)