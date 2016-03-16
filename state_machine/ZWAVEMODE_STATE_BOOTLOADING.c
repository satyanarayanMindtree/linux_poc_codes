#include<zwavemode_operation_pvt.h>


/**========================================    BOOT LOADING STATE    ================================================**/

static void handle_zwavemode_STATE_BOOT_LOADING_EVT_STATE_NORMAL(State_zwavemode *thiz)
{    
    State_zwavemode *state = ZwavemodeHandler_get_zwavemode_STATE_NORMAL(thiz->zwavemode_state_machine);
    
    if(DEBUG_MODE)
    {
        //printf("\n%s", __func__);
    }        
    
    ZwavemodeHandler_set_zwavemode_current_state(thiz->zwavemode_state_machine,state);        
}

static void handle_zwavemode_STATE_BOOT_LOADING_EVT_STATE_BOOT_LOADING_READY(State_zwavemode *thiz)
{    
    State_zwavemode *state = ZwavemodeHandler_get_zwavemode_STATE_BOOT_LOADING_READY(thiz->zwavemode_state_machine);
    
    if(DEBUG_MODE)
    {
        //printf("\n%s", __func__);
    }        
    
    ZwavemodeHandler_set_zwavemode_current_state(thiz->zwavemode_state_machine,state);        
}


static void handle_zwavemode_STATE_BOOT_LOADING_house_keeping(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);
}

static void handle_zwavemode_STATE_BOOT_LOADING_button_released(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);            

    // after button release timer should be off    
    thiz->zwavemode_state_machine->zwavemode_sw_timer_stop(thiz->zwavemode_state_machine->zwavemode_sw_timer_object);
    
    handle_zwavemode_STATE_BOOT_LOADING_EVT_STATE_BOOT_LOADING_READY(thiz);
}

int callback_zwavemode_STATE_BOOT_LOADING_timer_time_out(void *data)
{   
    State_zwavemode *state = (State_zwavemode *)data;

    if(state->handle_EVT_TIMER_TIME_OUT != NULL)
    {
        //printf("\n%s",__func__); 
        state->handle_EVT_TIMER_TIME_OUT(state);
    }    
    
    return 0;
}

static void handle_zwavemode_STATE_BOOT_LOADING_entry(State_zwavemode *thiz)
{
    #define BOOTLOADING_TO_NORMAL_TIMEOUT       3000

    zwavemode_sw_timer_handle timer_hnd;
    //LED__Command led_cmd = {LED_EVENT_START,LED_BOOT_LOADING_STATE};
    
    //printf("\n%s",__func__);  

    // feed led pattern 
    //LED__app_set_led_pattern(led_cmd);

    // on entry timer should be updated
    timer_hnd = thiz->zwavemode_state_machine->zwavemode_sw_timer_create(
                                                                            BOOTLOADING_TO_NORMAL_TIMEOUT,
                                                                            callback_zwavemode_STATE_BOOT_LOADING_timer_time_out,
                                                                            thiz->zwavemode_state_machine->zwavemode_sw_timer_object,
                                                                            (void*) thiz
                                                                        );
    if(thiz->zwavemode_state_machine->zwavemode_sw_timer_start(timer_hnd) == 0)
    {
        //error         
    }
}

static void handle_zwavemode_STATE_BOOT_LOADING_exit(State_zwavemode *thiz)
{
    //printf("\n%s",__func__); 
}

static State_zwavemode zwavemode_state = 
{
    .house_keeping                  = handle_zwavemode_STATE_BOOT_LOADING_house_keeping,
    .handle_EVT_BUTTON_RELEASED     = handle_zwavemode_STATE_BOOT_LOADING_button_released,
    .handle_EVT_TIMER_TIME_OUT      = handle_zwavemode_STATE_BOOT_LOADING_EVT_STATE_NORMAL,
    .entry                          = handle_zwavemode_STATE_BOOT_LOADING_entry,
    .exit                           = handle_zwavemode_STATE_BOOT_LOADING_exit,
};

State_zwavemode* get_zwavemode_STATE_BOOT_LOADING(){ return &zwavemode_state;}

/**========================================    BOOT LOADING STATE END    ================================================**/



/**========================================    BOOT LOADING REDAY STATE    ================================================**/

static void handle_zwavemode_STATE_BOOT_LOADING_READY_EVT_STATE_NORMAL(State_zwavemode *thiz)
{    
    State_zwavemode *state = ZwavemodeHandler_get_zwavemode_STATE_NORMAL(thiz->zwavemode_state_machine);
    
    if(DEBUG_MODE)
    {
        //printf("\n%s", __func__);
    }        
    
    ZwavemodeHandler_set_zwavemode_current_state(thiz->zwavemode_state_machine,state);        
}

static void handle_zwavemode_STATE_BOOT_LOADING_READY_EVT_STATE_BOOT_LOADING_EXECUTE(State_zwavemode *thiz)
{    
    State_zwavemode *state = ZwavemodeHandler_get_zwavemode_STATE_BOOT_LOADING_EXECUTE(thiz->zwavemode_state_machine);
    
    if(DEBUG_MODE)
    {
        //printf("\n%s", __func__);
    }        
    
    ZwavemodeHandler_set_zwavemode_current_state(thiz->zwavemode_state_machine,state);        
}


static void handle_zwavemode_STATE_BOOT_LOADING_READY_house_keeping(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);
}

static void handle_zwavemode_STATE_BOOT_LOADING_READY_button_released(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);
    
    // after button release timer should be off    
    thiz->zwavemode_state_machine->zwavemode_sw_timer_stop(thiz->zwavemode_state_machine->zwavemode_sw_timer_object);
    
    handle_zwavemode_STATE_BOOT_LOADING_READY_EVT_STATE_NORMAL(thiz);
}


int callback_zwavemode_STATE_BOOT_LOADING_READY_button_press_timer_time_out(void *data)
{
    State_zwavemode *thiz = (State_zwavemode *)data;
    
    handle_zwavemode_STATE_BOOT_LOADING_READY_EVT_STATE_BOOT_LOADING_EXECUTE(thiz);   
    
    return 0;
}

static void handle_zwavemode_STATE_BOOT_LOADING_READY_button_pressed(State_zwavemode *thiz)
{
    #define     BOOT_LOADING_READY_TO_EXECUTE_TIMEOUT 3000
    
    zwavemode_sw_timer_handle timer_hnd;
    
    //printf("\n%s",__func__);  
    
    // previuos timer should be off    
    thiz->zwavemode_state_machine->zwavemode_sw_timer_stop(thiz->zwavemode_state_machine->zwavemode_sw_timer_object);

    // on entry timer should be updated
    timer_hnd = thiz->zwavemode_state_machine->zwavemode_sw_timer_create(
                                                                          BOOT_LOADING_READY_TO_EXECUTE_TIMEOUT,
                                                                          callback_zwavemode_STATE_BOOT_LOADING_READY_button_press_timer_time_out, 
                                                                          thiz->zwavemode_state_machine->zwavemode_sw_timer_object,
                                                                          (void*) thiz
                                                                        );
    if(thiz->zwavemode_state_machine->zwavemode_sw_timer_start(timer_hnd) == 0)
    {
        //error
    }    
    
}

int callback_zwavemode_STATE_BOOT_LOADING_READY_normal_timer_time_out(void *data)
{
    State_zwavemode *state = (State_zwavemode *)data;

    if(state->handle_EVT_TIMER_TIME_OUT != NULL)
    {
        //printf("\n%s",__func__); 
        state->handle_EVT_TIMER_TIME_OUT(state);
    }    
    
    return 0;    
}

static void handle_zwavemode_STATE_BOOT_LOADING_READY_entry(State_zwavemode *thiz)
{
    #define BOOTLOADING_READY_TO_NORMAL_TIMEOUT 10000

    zwavemode_sw_timer_handle timer_hnd;
    //LED__Command led_cmd = {LED_EVENT_START,LED_BOOT_LOADING_READY_STATE};
    
    //printf("\n%s",__func__);  

    // feed led pattern 
    //LED__app_set_led_pattern(led_cmd);

    // on entry timer should be updated
    timer_hnd = thiz->zwavemode_state_machine->zwavemode_sw_timer_create(
                                                                            BOOTLOADING_READY_TO_NORMAL_TIMEOUT,
                                                                            callback_zwavemode_STATE_BOOT_LOADING_READY_normal_timer_time_out,
                                                                            thiz->zwavemode_state_machine->zwavemode_sw_timer_object,
                                                                            (void*) thiz
                                                                        );
    if(thiz->zwavemode_state_machine->zwavemode_sw_timer_start(timer_hnd) == 0)
    {
        //error
    }
}

static void handle_zwavemode_STATE_BOOT_LOADING_READY_exit(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);
}

static State_zwavemode zwavemode_state_ready = 
{
    .house_keeping                  = handle_zwavemode_STATE_BOOT_LOADING_READY_house_keeping,   
    .handle_EVT_BUTTON_PRESSED      = handle_zwavemode_STATE_BOOT_LOADING_READY_button_pressed,
    .handle_EVT_BUTTON_RELEASED     = handle_zwavemode_STATE_BOOT_LOADING_READY_button_released,//on button release enter in normal mode    
    .handle_EVT_TIMER_TIME_OUT      = handle_zwavemode_STATE_BOOT_LOADING_READY_EVT_STATE_NORMAL,
    .entry                          = handle_zwavemode_STATE_BOOT_LOADING_READY_entry,
    .exit                           = handle_zwavemode_STATE_BOOT_LOADING_READY_exit,    
};

State_zwavemode* get_zwavemode_STATE_BOOT_LOADING_READY(){ return &zwavemode_state_ready;}

/**========================================    BOOT LOADING REDAY STATE END    ================================================**/



/**========================================    BOOT LOADING EXECUTE STATE    ================================================**/

static void handle_zwavemode_STATE_BOOT_LOADING_EXECUTE_EVT_STATE_NORMAL(State_zwavemode *thiz)
{    
    State_zwavemode *state = ZwavemodeHandler_get_zwavemode_STATE_NORMAL(thiz->zwavemode_state_machine);
    
    if(DEBUG_MODE)
    {
        //printf("\n%s", __func__);
    }        
    
    ZwavemodeHandler_set_zwavemode_current_state(thiz->zwavemode_state_machine,state);        
}


static void handle_zwavemode_STATE_BOOT_LOADING_EXECUTE_house_keeping(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);
}

static void handle_zwavemodeSTATE_BOOT_LOADING_EXECUTE_button_released(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);            

    handle_zwavemode_STATE_BOOT_LOADING_EXECUTE_EVT_STATE_NORMAL(thiz);
}

static void handle_zwavemode_STATE_BOOT_LOADING_EXECUTE_entry(State_zwavemode *thiz)
{
    //LED__Command led_cmd = {LED_EVENT_START,LED_BOOT_LOADING_EXECUTE_STATE};
    
    //printf("\n%s",__func__);  

    // feed led pattern 
    //LED__app_set_led_pattern(led_cmd);
    
    printf("\nHere boot_loading code should be execute\n\n");
}

static void handle_zwavemode_STATE_BOOT_LOADING_EXECUTE_exit(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);
}

static State_zwavemode zwavemode_state_execute = 
{
    .house_keeping                  = handle_zwavemode_STATE_BOOT_LOADING_EXECUTE_house_keeping,
    .handle_EVT_BUTTON_RELEASED     = handle_zwavemodeSTATE_BOOT_LOADING_EXECUTE_button_released,// on button release enter in normal mode
    .entry                          = handle_zwavemode_STATE_BOOT_LOADING_EXECUTE_entry,
    .exit                           = handle_zwavemode_STATE_BOOT_LOADING_EXECUTE_exit,    
};

State_zwavemode* get_zwavemode_STATE_BOOT_LOADING_EXECUTE(){ return &zwavemode_state_execute;}

/**========================================    BOOT LOADING EXECUTE STATE END    ================================================**/
