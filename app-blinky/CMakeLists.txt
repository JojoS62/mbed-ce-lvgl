# Copyright (c) 2021 Arm Limited. All rights reserved.
# SPDX-License-Identifier: Apache-2.0

add_executable(blinky main.cpp)

target_link_libraries(blinky mbed-baremetal)

mbed_set_post_build(blinky)
