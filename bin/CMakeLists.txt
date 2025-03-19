# CMakeList.txt : CMake project for embeddedUtils, include source and define

# Add source to this project's executable.
add_executable (gbaTest "gbaTest.cpp")

target_include_directories(gbaTest PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(gbaTest PRIVATE gba)

if (WIN32)
    add_custom_command(
        TARGET gbaTest POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E copy $<TARGET_FILE:SDL3::SDL3-shared> $<TARGET_FILE_DIR:gbaTest>
        VERBATIM
    )
endif()

# TODO: Add tests and install targets if needed.
