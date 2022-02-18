cmake_minimum_required(VERSION 3.16)

project(ait_csp_tests VERSION 0.2.0 LANGUAGES CXX)

add_executable(tst_geometry geometry.cpp)
add_executable(tst_positioning positioning.cpp)

set_target_properties(tst_geometry tst_positioning PROPERTIES 
    CXX_STANDARD 17
    DEBUG_POSTFIX "_d"
    DEFINE_SYMBOL ""
    PUBLIC_HEADER ""
)

target_link_libraries(tst_geometry PUBLIC libu2d)
target_link_libraries(tst_positioning PUBLIC libu2d pthread)

add_test(NAME tst_geometry COMMAND tst_geometry)
add_test(NAME tst_positioning COMMAND tst_positioning)