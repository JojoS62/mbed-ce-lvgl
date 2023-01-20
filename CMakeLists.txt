cmake_minimum_required(VERSION 3.19)
cmake_policy(VERSION 3.19)

# Initialize Mbed OS build system. 
# Note: This block must be before the include of app.cmake
set(MBED_APP_JSON_PATH mbed_app.json)
set(CUSTOM_TARGETS_JSON_PATH custom_targets.json) # This activates the custom targets in custom_targets.json

include(mbed-os/tools/cmake/app.cmake)

# Include folder with the custom targets.
# This needs to be done before add_subdirectory(mbed-os).
add_subdirectory(custom_targets)
add_subdirectory(mbed-os)

project(test-lvgl)

# add subdirectories and build targets here
add_executable(app-blinky app-blinky/main.cpp)
target_link_libraries(app-blinky  
#     mbed-os
    mbed-baremetal
) # Can also link to mbed-baremetal here

mbed_set_post_build(app-blinky )

mbed_finalize_build()