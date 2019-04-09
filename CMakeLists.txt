cmake_minimum_required(VERSION 3.11)

project(algorithms)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB PROGRAM_SRC
  "*.hpp"
  "*.cpp"
  "helper/*.hpp"
  "sort/*.hpp"
  "structures/*.hpp"
)

add_executable(${PROJECT_NAME} ${PROGRAM_SRC})
target_include_directories(${PROJECT_NAME} PUBLIC ./)
