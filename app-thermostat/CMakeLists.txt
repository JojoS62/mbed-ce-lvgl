# Copyright (c) 2021 Arm Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

add_executable(thermostat main.cpp)

add_library(lvgl ALIAS lvgl_interface)      # for compatibility with static/interface libs

target_include_directories(thermostat 
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}
        "${LIB_PATH}lvgl"
)

target_compile_definitions(thermostat PRIVATE
    LV_CONF_SUPPRESS_DEFINE_CHECK
)

target_link_libraries(thermostat  PRIVATE
    mbed-baremetal
    lvglDriver
)

mbed_set_post_build(thermostat)
