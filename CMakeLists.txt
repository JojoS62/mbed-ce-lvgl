cmake_minimum_required(VERSION 3.19)
cmake_policy(VERSION 3.19)

# Initialize Mbed OS build system. 
# Note: This block must be before the include of app.cmake
set(MBED_APP_JSON_PATH mbed_app.json)

include(mbed-os/tools/cmake/app.cmake)
add_subdirectory(mbed-os)

project(test-lvgl)

# add subdirectories and build targets here
add_executable(app-blinky app-blinky/main.cpp)
target_link_libraries(app-blinky  mbed-os) # Can also link to mbed-baremetal here
mbed_set_post_build(app-blinky )

mbed_finalize_build()