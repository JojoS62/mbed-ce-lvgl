#include "mbed.h"
#include "lvgl.h"
#include "LVGLDispDriver_ILI9341.h"

DigitalOut led(LED1);
DigitalOut testPin(PA_4);

using rtos::Kernel::Clock;
static Ticker tickerLvgl;

//
// lv Ticker, executed in interrupt context
//

void fnLvTicker()
{
    lv_tick_inc(2); /*Tell LittlevGL that 2 milliseconds were elapsed*/
}


//
//  sleep and call lvHandler cyclic
//   sleeptime_ms: >0: sleep milliseconds, 0: sleep forever

void sleepWithLvHandler(chrono::milliseconds sleepTime)
{
    Clock::duration_u32 elapsedTime = 0ms;
    Clock::duration_u32 timeSlice = 5ms;

    while (elapsedTime <= sleepTime) {
        lv_task_handler();

        ThisThread::sleep_for(timeSlice);
        if (sleepTime > 0ms) {
            elapsedTime += timeSlice;
        }
    }
}

typedef void (*lv_update_cb_t)(bool);

[[maybe_unused]] static void lv_screen_update(lv_timer_t* timer)
{
	static lv_obj_t* lastScreen = 0;
	bool firstStart;

	lv_obj_t* actScreen = lv_disp_get_scr_act((lv_disp_t*)timer->user_data);
	firstStart = (actScreen != lastScreen);
	lastScreen = actScreen;

	if (actScreen && actScreen->user_data) {
		((lv_update_cb_t)actScreen->user_data)(firstStart);
	}
}

void btn_event_cb(lv_event_t * e)
{
    printf("Clicked\n");
}

void create_lv_screen(lv_disp_t* disp) 
{
    lv_obj_t * scr = lv_disp_get_scr_act(disp);

    lv_obj_t * btn = lv_btn_create(scr);                            /*Add a button to the current screen*/
    MBED_ASSERT(btn);
    lv_obj_set_size(btn, 100, 50);                                  /*Set its size*/
    lv_obj_center(btn);   
    lv_obj_add_event_cb(btn, btn_event_cb, LV_EVENT_CLICKED, NULL); /*Assign a callback to the button*/

    lv_obj_t * label = lv_label_create(btn);                        /*Add a label to the button*/
    MBED_ASSERT(label);
    lv_label_set_text(label, "hello");                              /*Set the labels text*/
    lv_obj_center(label);                                           /*Align the label to the center*/
}



int main()
{
    DeepSleepLock lock;
    
    printf("Test lvgl thermostat\n");
    printf("Hello from "  MBED_STRINGIFY(TARGET_NAME) "\n");
    printf("Mbed OS version: %d.%d.%d\n\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
	
	SPI spi(PB_5, PB_4, PB_3);
	spi.frequency(20'000'000);
	
    LVGLDispILI9341  lvglDisplay(spi, PA_15, PB_6, PB_7, PA_12, 10);

    tickerLvgl.attach(&fnLvTicker, 2ms);

    create_lv_screen(lvglDisplay.getLVDisp());

	while(true) {
		led = !led;
		testPin = !testPin;

        sleepWithLvHandler(50ms);
	}

	return 0;
}

// workaround for missing functions since gcc 11.3
extern "C" {
    void _kill() {};
    void _getpid() {};
}