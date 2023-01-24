# Copyright (c) 2021 Arm Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

add_executable(thermostat 
    main.cpp
    gui/ui_font_Number.c
    gui/ui_helpers.c
    gui/ui.c
    gui/ui_events.c
)

add_library(lvgl ALIAS lvgl_interface)      # for compatibility with static/interface libs

target_include_directories(thermostat 
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}
        "${LIB_PATH}lvgl"
)

target_compile_definitions(thermostat PRIVATE
    LV_LVGL_H_INCLUDE_SIMPLE
    LV_CONF_SUPPRESS_DEFINE_CHECK
)

target_link_libraries(thermostat  PRIVATE
    mbed-baremetal
    lvglDriver
)

mbed_set_post_build(thermostat)
