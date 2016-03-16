#include<zwavemode_operation_pvt.h>


/**=====================================    SYSTEM CLEARING STATE    ===================================================**/

static void handle_zwavemode_STATE_SYSTEM_CLEARING_EVT_STATE_BOOT_LOADING(State_zwavemode *thiz)
{    
    State_zwavemode *state = ZwavemodeHandler_get_zwavemode_STATE_BOOT_LOADING(thiz->zwavemode_state_machine);
    
    if(DEBUG_MODE)
    {
        //printf("\n%s", __func__);
    }        
    
    ZwavemodeHandler_set_zwavemode_current_state(thiz->zwavemode_state_machine,state);        
}

static void handle_zwavemode_STATE_SYSTEM_CLEARING_EVT_STATE_SYSTEM_CLEARING_READY(State_zwavemode *thiz)
{    
    State_zwavemode *state = ZwavemodeHandler_get_zwavemode_STATE_SYSTEM_CLEARING_READY(thiz->zwavemode_state_machine);
    
    if(DEBUG_MODE)
    {
        //printf("\n%s", __func__);
    }        
    
    ZwavemodeHandler_set_zwavemode_current_state(thiz->zwavemode_state_machine,state);        
}


static void handle_zwavemode_STATE_SYSTEM_CLEARING_house_keeping(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);
}

static void handle_zwavemode_STATE_SYSTEM_CLEARING_button_released(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);            
    
    // after button release timer should be off    
    thiz->zwavemode_state_machine->zwavemode_sw_timer_stop(thiz->zwavemode_state_machine->zwavemode_sw_timer_object);

    handle_zwavemode_STATE_SYSTEM_CLEARING_EVT_STATE_SYSTEM_CLEARING_READY(thiz);
}

int callback_zwavemode_STATE_SYSTEM_CLEARING_timer_time_out(void *data)
{   
    State_zwavemode *state = (State_zwavemode *)data;

    if(state->handle_EVT_TIMER_TIME_OUT != NULL)
    {
        //printf("\n%s",__func__); 
        state->handle_EVT_TIMER_TIME_OUT(state);
    }    
    
    return 0;
}

static void handle_zwavemode_STATE_SYSTEM_CLEARING_entry(State_zwavemode *thiz)
{
    #define     SYSTEMCLEAR_TO_BOOTLOADING_TIMEOUT      3000

    zwavemode_sw_timer_handle timer_hnd;
    //LED_Command led_cmd = {LED_EVENT_START,LED_SYSTEM_CLEARING_STATE};
    
    //printf("\n%s",__func__);  

    // feed led pattern 
    //LED_app_set_led_pattern(led_cmd);

    // on entry timer should be updated
    timer_hnd = thiz->zwavemode_state_machine->zwavemode_sw_timer_create(
                                                                            SYSTEMCLEAR_TO_BOOTLOADING_TIMEOUT,
                                                                            callback_zwavemode_STATE_SYSTEM_CLEARING_timer_time_out,
                                                                            thiz->zwavemode_state_machine->zwavemode_sw_timer_object,
                                                                            (void*) thiz
                                                                        );
    if(thiz->zwavemode_state_machine->zwavemode_sw_timer_start(timer_hnd) == 0)
    {
        //error
    }   
}

static void handle_zwavemode_STATE_SYSTEM_CLEARING_exit(State_zwavemode *thiz)
{
    //printf("\n%s",__func__); 
}

static State_zwavemode zwavemode_state = 
{
    .house_keeping                  = handle_zwavemode_STATE_SYSTEM_CLEARING_house_keeping,
    .handle_EVT_BUTTON_RELEASED     = handle_zwavemode_STATE_SYSTEM_CLEARING_button_released,
    .handle_EVT_TIMER_TIME_OUT      = handle_zwavemode_STATE_SYSTEM_CLEARING_EVT_STATE_BOOT_LOADING,
    .entry                          = handle_zwavemode_STATE_SYSTEM_CLEARING_entry,
    .exit                           = handle_zwavemode_STATE_SYSTEM_CLEARING_exit,
};

State_zwavemode* get_zwavemode_STATE_SYSTEM_CLEARING(){ return &zwavemode_state;}

/**===================================    SYSTEM CLEARING STATE END    =================================================**/



/**====================================    SYSTEM CLEARING READY STATE    ==============================================**/

static void handle_zwavemode_STATE_SYSTEM_CLEARING_READY_EVT_STATE_SYSTEM_CLEARING_EXECUTE(State_zwavemode *thiz)
{    
    State_zwavemode *state = ZwavemodeHandler_get_zwavemode_STATE_SYSTEM_CLEARING_EXECUTE(thiz->zwavemode_state_machine);
    
    if(DEBUG_MODE)
    {
        //printf("\n%s", __func__);
    }        
    
    ZwavemodeHandler_set_zwavemode_current_state(thiz->zwavemode_state_machine,state);        
}

static void handle_zwavemode_STATE_SYSTEM_CLEARING_READY_EVT_STATE_NORMAL(State_zwavemode *thiz)
{    
    State_zwavemode *state = ZwavemodeHandler_get_zwavemode_STATE_NORMAL(thiz->zwavemode_state_machine);
    
    if(DEBUG_MODE)
    {
        //printf("\n%s", __func__);
    }        
    
    ZwavemodeHandler_set_zwavemode_current_state(thiz->zwavemode_state_machine,state);        
}


static void handle_zwavemode_STATE_SYSTEM_CLEARING_READY_house_keeping(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);    
}

static void handle_zwavemode_STATE_SYSTEM_CLEARING_READY_button_released(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);
    
    // after button release timer should be off    
    thiz->zwavemode_state_machine->zwavemode_sw_timer_stop(thiz->zwavemode_state_machine->zwavemode_sw_timer_object);
    
    handle_zwavemode_STATE_SYSTEM_CLEARING_READY_EVT_STATE_NORMAL(thiz);
}

int callback_zwavemode_STATE_SYSTEM_CLEARING_READY_button_press_timer_time_out(void *data)
{
    State_zwavemode *thiz = (State_zwavemode *)data;
    
    handle_zwavemode_STATE_SYSTEM_CLEARING_READY_EVT_STATE_SYSTEM_CLEARING_EXECUTE(thiz);   
    
    return 0;
}

static void handle_zwavemode_STATE_SYSTEM_CLEARING_READY_button_pressed(State_zwavemode *thiz)
{
    #define     SYSTEM_CLEARING_READY_TO_EXECUTE_TIMEOUT 3000
    
    zwavemode_sw_timer_handle timer_hnd;
    
    //printf("\n%s",__func__);  
    
    // previuos timer should be off    
    thiz->zwavemode_state_machine->zwavemode_sw_timer_stop(thiz->zwavemode_state_machine->zwavemode_sw_timer_object);

    // on entry timer should be updated
    timer_hnd = thiz->zwavemode_state_machine->zwavemode_sw_timer_create(
                                                                          SYSTEM_CLEARING_READY_TO_EXECUTE_TIMEOUT,
                                                                          callback_zwavemode_STATE_SYSTEM_CLEARING_READY_button_press_timer_time_out, 
                                                                          thiz->zwavemode_state_machine->zwavemode_sw_timer_object,
                                                                          (void*) thiz
                                                                        );
    if(thiz->zwavemode_state_machine->zwavemode_sw_timer_start(timer_hnd) == 0)
    {
        //error
    }    
    
}

int callback_zwavemode_STATE_SYSTEM_CLEARING_READY_normal_timer_time_out(void *data)
{
    State_zwavemode *state = (State_zwavemode *)data;

    if(state->handle_EVT_TIMER_TIME_OUT != NULL)
    {
        //printf("\n%s",__func__); 
        state->handle_EVT_TIMER_TIME_OUT(state);
    }    
    
    return 0;    
}

static void handle_zwavemode_STATE_SYSTEM_CLEARING_READY_entry(State_zwavemode *thiz)
{
    #define     SYSTEM_CLEARING_READY_TO_NORMAL_TIMEOUT 10000

    zwavemode_sw_timer_handle timer_hnd;
    //LED_Command led_cmd = {LED_EVENT_START,LED_SYSTEM_CLEARING_READY_STATE};
    
    //printf("\n%s",__func__);  

    // feed led pattern 
    //LED_app_set_led_pattern(led_cmd);

    // on entry timer should be updated
    timer_hnd = thiz->zwavemode_state_machine->zwavemode_sw_timer_create(
                                                                            SYSTEM_CLEARING_READY_TO_NORMAL_TIMEOUT,
                                                                            callback_zwavemode_STATE_SYSTEM_CLEARING_READY_normal_timer_time_out, 
                                                                            thiz->zwavemode_state_machine->zwavemode_sw_timer_object,
                                                                            (void*) thiz
                                                                        );
    if(thiz->zwavemode_state_machine->zwavemode_sw_timer_start(timer_hnd) == 0)
    {
        //error
    }    
}

static void handle_zwavemode_STATE_SYSTEM_CLEARING_READY_exit(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);
}

static State_zwavemode zwavemode_state_ready = 
{
    .house_keeping                  = handle_zwavemode_STATE_SYSTEM_CLEARING_READY_house_keeping,
    .handle_EVT_BUTTON_PRESSED      = handle_zwavemode_STATE_SYSTEM_CLEARING_READY_button_pressed,
    .handle_EVT_BUTTON_RELEASED     = handle_zwavemode_STATE_SYSTEM_CLEARING_READY_button_released,//on button release enter in normal mode
    .handle_EVT_TIMER_TIME_OUT      = handle_zwavemode_STATE_SYSTEM_CLEARING_READY_EVT_STATE_NORMAL,
    .entry                          = handle_zwavemode_STATE_SYSTEM_CLEARING_READY_entry,
    .exit                           = handle_zwavemode_STATE_SYSTEM_CLEARING_READY_exit,    
};

State_zwavemode* get_zwavemode_STATE_SYSTEM_CLEARING_READY(){ return &zwavemode_state_ready;}

/**===================================    SYSTEM CLEARING READY STATE END    ===========================================**/



/**===================================    SYSTEM CLEARING EXECUTE STATE    =============================================**/

static void handle_zwavemode_STATE_SYSTEM_CLEARING_EXECUTE_EVT_STATE_NORMAL(State_zwavemode *thiz)
{    
    State_zwavemode *state = ZwavemodeHandler_get_zwavemode_STATE_NORMAL(thiz->zwavemode_state_machine);
    
    if(DEBUG_MODE)
    {
        //printf("\n%s", __func__);
    }        
    
    ZwavemodeHandler_set_zwavemode_current_state(thiz->zwavemode_state_machine,state);        
}


static void handle_zwavemode_STATE_SYSTEM_CLEARING_EXECUTE_house_keeping(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);
}

static void handle_zwavemode_STATE_SYSTEM_CLEARING_EXECUTE_button_released(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);            

    handle_zwavemode_STATE_SYSTEM_CLEARING_EXECUTE_EVT_STATE_NORMAL(thiz);
}

static void handle_zwavemode_STATE_SYSTEM_CLEARING_EXECUTE_entry(State_zwavemode *thiz)
{
    //LED_Command led_cmd = {LED_EVENT_START,LED_SYSTEM_CLEARING_EXECUTE_STATE};
    
    //printf("\n%s",__func__);  

    // feed led pattern 
    //LED_app_set_led_pattern(led_cmd);
    
    printf("\nHere system_clearing code should be execute\n\n");

}

static void handle_zwavemode_STATE_SYSTEM_CLEARING_EXECUTE_exit(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);    
}

static State_zwavemode zwavemode_state_execute = 
{
    .house_keeping                  = handle_zwavemode_STATE_SYSTEM_CLEARING_EXECUTE_house_keeping,
    .handle_EVT_BUTTON_RELEASED     = handle_zwavemode_STATE_SYSTEM_CLEARING_EXECUTE_button_released,//if button release then enter in normal mode
    .entry                          = handle_zwavemode_STATE_SYSTEM_CLEARING_EXECUTE_entry,
    .exit                           = handle_zwavemode_STATE_SYSTEM_CLEARING_EXECUTE_exit,    
};

State_zwavemode* get_zwavemode_STATE_SYSTEM_CLEARING_EXECUTE(){ return &zwavemode_state_execute;}

/**===================================    SYSTEM CLEARING EXECUTE STATE END    ===========================================**/
