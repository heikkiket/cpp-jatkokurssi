cmake_minimum_required(VERSION 3.10)
project(Jatkokurssi)

## Needed for c++17 and c++20 features
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a")

## GOOGLE test
enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


## PROJECT files
add_executable(smart_ptr teht1_smart_pointers/main.cpp
  teht1_smart_pointers/Henkilo.cpp
  teht1_smart_pointers/Manageri.cpp
  )

## Tests
# add_executable(runTests teht1_smart_pointers/tests.cpp
#   teht1_smart_pointers/Test.cpp
#   )


# target_link_libraries(runTests gtest gtest_main)
# target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# add_test(iteratorStackTests iteratorStackTests)
