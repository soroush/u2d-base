cmake_minimum_required(VERSION 3.16)

project(libu2d VERSION 0.2.0 LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED
    src/geometry/algebra.cpp
    src/geometry/geometry.cpp

    src/network/connection.cpp

    src/parser/parser.cpp
    src/parser/scanner.cpp
    
    # src/perception/visual-objects/ball.cpp
    # src/perception/visual-objects/flag.cpp
    # src/perception/visual-objects/line.cpp
    # src/perception/visual-objects/player.cpp

    src/perception/model.cpp
    src/perception/server_param.cpp
    src/perception/player_param.cpp
    src/perception/marks.cpp
    src/perception/flags.cpp
    src/perception/visual_object.cpp
    src/perception/detailed_visual_object.cpp
    src/perception/body.cpp
    src/perception/player.cpp

    #src/perception/field.cpp
    #src/perception/see.cpp

    src/agent.cpp
    src/command.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES 
    CXX_STANDARD 17
    DEBUG_POSTFIX "_d"
    DEFINE_SYMBOL ""
    PUBLIC_HEADER ""
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Installation

include(GNUInstallDirs)

export(TARGETS ${PROJECT_NAME} FILE "${PROJECT_NAME}Targets.cmake")

install(TARGETS ${PROJECT_NAME}
    EXPORT "${PROJECT_NAME}Targets"
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/u2d
)

install(DIRECTORY "include/u2d" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${PROJECT_NAME}ConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(EXPORT "${PROJECT_NAME}Targets"
    FILE "${PROJECT_NAME}Targets.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/
)

install(FILES "cmake/${PROJECT_NAME}Config.cmake" "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/
)

enable_testing()
add_subdirectory(test)