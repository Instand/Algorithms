cmake_minimum_required(VERSION 3.11)

project(algorithms CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(TEST_NAME tests)

enable_testing()

add_subdirectory(third-party)

file(GLOB PROGRAM_SRC
  "*.hpp"
  "*.cpp"
  "sort/*.hpp"
  "structures/*.hpp"
  "tests/*cpp"
)

if (MSVC)
  add_definitions(-DNOMINMAX)
  add_definitions(-D_WIN32_WINNT=0x0601)
  add_definitions(-D_SILENCE_CXX17_ALLOCATOR_VOID_DEPRECATION_WARNING)
  add_definitions(-D_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING)
  add_definitions(-D_ENABLE_EXTENDED_ALIGNED_STORAGE)
endif()

macro(configure_msvc_runtime)
  if(MSVC)
    # Default to statically-linked runtime.
    if("${MSVC_RUNTIME}" STREQUAL "")
      set(MSVC_RUNTIME "static")
    endif()
    # Set compiler options.
    set(variables
      CMAKE_C_FLAGS_DEBUG
      CMAKE_C_FLAGS_MINSIZEREL
      CMAKE_C_FLAGS_RELEASE
      CMAKE_C_FLAGS_RELWITHDEBINFO
      CMAKE_C_FLAGS_RELMONITOR
      CMAKE_C_FLAGS_RELWALLET
      CMAKE_CXX_FLAGS_DEBUG
      CMAKE_CXX_FLAGS_MINSIZEREL
      CMAKE_CXX_FLAGS_RELEASE
      CMAKE_CXX_FLAGS_RELMONITOR
      CMAKE_CXX_FLAGS_RELWALLET
      CMAKE_CXX_FLAGS_RELWITHDEBINFO
    )
    if(${MSVC_RUNTIME} STREQUAL "static")
      message(STATUS
        "MSVC -> forcing use of statically-linked runtime."
      )
      foreach(variable ${variables})
        if(${variable} MATCHES "/MD")
          string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
        endif()
      endforeach()
    else()
      message(STATUS
        "MSVC -> forcing use of dynamically-linked runtime."
      )
      foreach(variable ${variables})
        if(${variable} MATCHES "/MT")
          string(REGEX REPLACE "/MT" "/MD" ${variable} "${${variable}}")
        endif()
      endforeach()
    endif()
  endif()
endmacro()

configure_msvc_runtime()

add_executable(${TEST_NAME} ${PROGRAM_SRC})

target_include_directories(${TEST_NAME} PUBLIC ./)
target_link_libraries(${TEST_NAME} gtest)

add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
