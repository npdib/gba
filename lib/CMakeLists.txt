# Add source to this project's executable.

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(embeddedUtils)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET embeddedUtils PROPERTY CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

# TODO: Add tests and install targets if needed.
