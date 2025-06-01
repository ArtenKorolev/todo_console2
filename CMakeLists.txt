cmake_minimum_required(VERSION 3.10)
project(todo)
find_package(nlohmann_json REQUIRED)

# includes 
include_directories(
    "${CMAKE_SOURCE_DIR}/code/entities"
    "${CMAKE_SOURCE_DIR}/code/repository"
    "${CMAKE_SOURCE_DIR}/code/entities"
    "${CMAKE_SOURCE_DIR}/code/config"
    "${CMAKE_SOURCE_DIR}/code/json_serialiaztion"
)

# sources
file(
    GLOB SOURCES 
    "code/entities"
    "code/repository"
    "code/config"
    "code/json_serialiaztion"
    "code/main.cpp"
)

add_executable(${PROJECT_NAME} ${SOURCES})

# linking json lib
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)