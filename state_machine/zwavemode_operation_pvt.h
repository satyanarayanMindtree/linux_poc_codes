#ifndef __ZWAVEMODE_OPERATION_PVT_H__
#define __ZWAVEMODE_OPERATION_PVT_H__

#include <sw_timer.h> 
#include<datatypes.h>

#define NEW_ZwaveModeHandler()  {.zwavemode_current_state = NULL}


// ------------------ Zwave Mode operation state machine -------------------------------//

typedef struct __ZwaveModeHandler  ZwaveModeHandler;

typedef struct __State_zwavemode  State_zwavemode;

typedef sw_timer            zwavemode_sw_timer;
typedef sw_timer_handle     zwavemode_sw_timer_handle;
typedef zwavemode_sw_timer_handle (*zwavemode_sw_timer_update_fun)(int, cb_func_ptr,sw_timer * ,void* );
typedef int(*zwavemode_sw_timer_stop_fun)(zwavemode_sw_timer_handle);
typedef int(*zwavemode_sw_timer_start_fun)(zwavemode_sw_timer_handle);

struct __State_zwavemode
{
    ZwaveModeHandler *zwavemode_state_machine;
       
    void (*entry) (State_zwavemode *thiz);
    void (*exit) (State_zwavemode *thiz);
    void (*house_keeping) (State_zwavemode *thiz);
    void (*handle_EVT_BUTTON_PRESSED) (State_zwavemode *thiz);
    void (*handle_EVT_BUTTON_RELEASED) (State_zwavemode *thiz);
    void (*handle_EVT_TIMER_TIME_OUT) (State_zwavemode *thiz);
};

struct __ZwaveModeHandler  
{
    
    zwavemode_sw_timer              *zwavemode_sw_timer_object;
    zwavemode_sw_timer_update_fun   zwavemode_sw_timer_create;
    zwavemode_sw_timer_stop_fun     zwavemode_sw_timer_stop;
    zwavemode_sw_timer_start_fun    zwavemode_sw_timer_start;
    
    State_zwavemode *zwavemode_current_state;
        
    State_zwavemode *zwavemode_state_normal;
    
    State_zwavemode *zwavemode_state_inclusion;
    State_zwavemode *zwavemode_state_inclusion_execute;
    
    State_zwavemode *zwavemode_state_system_clearing;
    State_zwavemode *zwavemode_state_system_clearing_ready;
    State_zwavemode *zwavemode_state_system_clearing_execute;
    
    State_zwavemode *zwavemode_state_boot_loading;
    State_zwavemode *zwavemode_state_boot_loading_ready;
    State_zwavemode *zwavemode_state_boot_loading_execute;
    
    State_zwavemode *zwavemode_state_faulty;    
};




State_zwavemode* get_zwavemode_STATE_NORMAL();

State_zwavemode* get_zwavemode_STATE_INCLUSION();
State_zwavemode* get_zwavemode_STATE_INCLUSION_EXECUTE();


State_zwavemode* get_zwavemode_STATE_SYSTEM_CLEARING();
State_zwavemode* get_zwavemode_STATE_SYSTEM_CLEARING_READY();
State_zwavemode* get_zwavemode_STATE_SYSTEM_CLEARING_EXECUTE();

State_zwavemode* get_zwavemode_STATE_BOOT_LOADING();
State_zwavemode* get_zwavemode_STATE_BOOT_LOADING_READY();
State_zwavemode* get_zwavemode_STATE_BOOT_LOADING_EXECUTE();

State_zwavemode* get_zwavemode_STATE_FAULTY();


State_zwavemode* ZwavemodeHandler_get_zwavemode_STATE_NORMAL(ZwaveModeHandler *thiz);

State_zwavemode* ZwavemodeHandler_get_zwavemode_STATE_INCLUSION(ZwaveModeHandler *thiz);
State_zwavemode* ZwavemodeHandler_get_zwavemode_STATE_INCLUSION_EXECUTE(ZwaveModeHandler *thiz);

State_zwavemode* ZwavemodeHandler_get_zwavemode_STATE_SYSTEM_CLEARING(ZwaveModeHandler *thiz);
State_zwavemode* ZwavemodeHandler_get_zwavemode_STATE_SYSTEM_CLEARING_READY(ZwaveModeHandler *thiz);
State_zwavemode* ZwavemodeHandler_get_zwavemode_STATE_SYSTEM_CLEARING_EXECUTE(ZwaveModeHandler *thiz);

State_zwavemode* ZwavemodeHandler_get_zwavemode_STATE_BOOT_LOADING(ZwaveModeHandler *thiz);
State_zwavemode* ZwavemodeHandler_get_zwavemode_STATE_BOOT_LOADING_READY(ZwaveModeHandler *thiz);
State_zwavemode* ZwavemodeHandler_get_zwavemode_STATE_BOOT_LOADING_EXECUTE(ZwaveModeHandler *thiz);

State_zwavemode* ZwavemodeHandler_get_zwavemode_STATE_FAULTY(ZwaveModeHandler *thiz);

void ZwavemodeHandler_set_zwavemode_current_state(ZwaveModeHandler *thiz, State_zwavemode *state);


void ZwavemodeHandler_handle_EVT_BUTTON_RELEASE (ZwaveModeHandler *thiz);
void ZwavemodeHandler_handle_EVT_BUTTON_PRESS (ZwaveModeHandler *thiz);


#endif