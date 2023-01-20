add_library(mbed-robotdyn-f303cc INTERFACE)

target_sources(mbed-robotdyn-f303cc INTERFACE 
    ROBOTDYN_F303CC/PeripheralPins.c
    ROBOTDYN_F303CC/system_clock.c
)

target_include_directories(mbed-robotdyn-f303cc INTERFACE 
    ROBOTDYN_F303CC
    .
)

target_link_libraries(mbed-robotdyn-f303cc  INTERFACE 
    mbed-stm32f303xc
)
