cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(PacManTests
  LANGUAGES CXX
)

# ---- Options ----

option(ENABLE_TEST_COVERAGE "Enable test coverage" OFF)
option(TEST_INSTALLED_VERSION "Test the version found by find_package" OFF)

# --- Import tools ----

include(../cmake/tools.cmake)

# ---- Dependencies ----

include(../cmake/CPM.cmake)

CPMAddPackage(
  NAME doctest
  GITHUB_REPOSITORY onqtam/doctest
  GIT_TAG 2.3.7
)

if (TEST_INSTALLED_VERSION)
  find_package(PacMan REQUIRED)
else()
  CPMAddPackage(
    NAME PacMan
    SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..
  )
endif()

CPMAddPackage(
  NAME Format.cmake
  VERSION 1.5
  GITHUB_REPOSITORY TheLartians/Format.cmake
  # enable cmake formatting
  OPTIONS "FORMAT_CHECK_CMAKE ON"
)

# ---- Copy resources to build folder ----
FILE(COPY ../resources/ DESTINATION "${CMAKE_BINARY_DIR}/resources")

# ---- Create binary ----

file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/source/**/*.cpp)
add_executable(PacManTests ${sources})
target_link_libraries(PacManTests doctest PacMan SDL2 SDL2_ttf SDL2_mixer glm)

set_target_properties(PacManTests PROPERTIES CXX_STANDARD 17)

# enable compiler warnings
if (NOT TEST_INSTALLED_VERSION)
  if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_compile_options(PacMan PUBLIC -Wall -Wextra)
  elseif(MSVC)
    target_compile_options(PacMan PUBLIC /W4 /WX)
    target_compile_definitions(PacManTests PUBLIC DOCTEST_CONFIG_USE_STD_HEADERS)
  endif()
endif()

# ---- Add PacManTests ----

ENABLE_TESTING() 

# Note: doctest and similar testing frameworks can automatically configure CMake tests
# For other testing frameworks add the tests target instead:
# ADD_TEST(PacManTests PacManTests)

include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
doctest_discover_tests(PacManTests)

# ---- code coverage ----

if (ENABLE_TEST_COVERAGE)
  target_compile_options(PacMan PUBLIC -O0 -g -fprofile-arcs -ftest-coverage)
  target_link_options(PacMan PUBLIC -fprofile-arcs -ftest-coverage)
endif()
