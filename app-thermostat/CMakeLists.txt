# Copyright (c) 2021 Arm Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

add_executable(thermostat 
    main.cpp
    gui/ui_comp.c 
    gui/ui_font_Number.c 
    gui/ui_helpers.c 
    # gui/ui_img_album_png.c 
    # gui/ui_img_avatar_png.c 
    gui/ui_img_backward_png.c 
    # gui/ui_img_chatbox_png.c 
    # gui/ui_img_chatbox2_png.c 
    gui/ui_img_clock_hour_png.c 
    gui/ui_img_clock_min_png.c 
    gui/ui_img_clock_sec_png.c 
    gui/ui_img_cloud_png.c 
    gui/ui_img_forward_png.c 
    gui/ui_img_pattern_png.c 
    gui/ui_img_phone_png.c 
    gui/ui_img_play_png.c 
    gui/ui_img_sls_logo_png.c 
    gui/ui_img_weather_1_png.c 
    gui/ui_img_weather_2_png.c 
    gui/ui_img_weather_3_png.c 
    gui/ui.c
)

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
