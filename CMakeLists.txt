cmake_minimum_required(VERSION 3.19)
cmake_policy(VERSION 3.19)

# Initialize Mbed OS build system. 
# Note: This block must be before the include of app.cmake
set(MBED_APP_JSON_PATH mbed_app.json)
set(CUSTOM_TARGETS_JSON_PATH custom_targets.json) # This activates the custom targets in custom_targets.json
set(MBED_MEMAP_DEPTH 3)
set(LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/libs/")
set(MICROPY_DIR TRUE)                       # force lvgl to create an interface lib

set(UPLOAD_METHOD "STM32CUBE") 
set(STM32CUBE_UPLOAD_ENABLED TRUE)
set(STM32CUBE_CONNECT_COMMAND -c port=SWD reset=HWrst)
set(STM32CUBE_GDBSERVER_ARGS --swd)

include(mbed-os/tools/cmake/app.cmake)

# Include folder with the custom targets.
# This needs to be done before add_subdirectory(mbed-os).
add_subdirectory(custom_targets)
add_subdirectory(mbed-os)
add_subdirectory(${LIB_PATH} libs)

project(test-lvgl)

add_subdirectory(app-blinky)
add_subdirectory(app-thermostat)

mbed_finalize_build()