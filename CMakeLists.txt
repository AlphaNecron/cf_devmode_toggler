cmake_minimum_required(VERSION 3.14)
project(cf_devmode_toggler)

set(CMAKE_CXX_STANDARD 14)
include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/whoshuu/cpr.git GIT_TAG f4622efcb59d84071ae11404ae61bd821c1c344b)
FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_TAG v3.9.1)
FetchContent_MakeAvailable(json)
set(ENV{CPR_BUILD_TESTS} OFF)
FetchContent_MakeAvailable(cpr)
add_executable(devmode-toggle main.cpp)
target_link_libraries(devmode-toggle PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(devmode-toggle PRIVATE cpr::cpr)
