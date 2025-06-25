cmake_minimum_required(VERSION 3.20)
project(MyCppProject)

# Enable C++17 or later
set(CMAKE_CXX_STANDARD 17)

# Let CMake know about vcpkg
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

add_executable(main main.cpp)
add_library(core STATIC main.cpp) # reuse in tests
target_compile_features(core PUBLIC cxx_std_17)

# Testing
include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.0
)
FetchContent_MakeAvailable(catch2)

enable_testing()
add_executable(tests test/test_main.cpp)
target_link_libraries(tests PRIVATE core Catch2::Catch2WithMain)
include(Catch)
catch_discover_tests(tests)

