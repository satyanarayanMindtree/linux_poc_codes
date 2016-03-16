#include<zwavemode_operation_pvt.h>


/**========================================    INCLUSION STATE    ================================================**/

static void handle_zwavemode_STATE_INCLUSION_EVT_STATE_INCLUSION_EXECUTE(State_zwavemode *thiz)
{    
    State_zwavemode *state = ZwavemodeHandler_get_zwavemode_STATE_INCLUSION_EXECUTE(thiz->zwavemode_state_machine);
    
    if(DEBUG_MODE)
    {
        //printf("\n%s", __func__);
    }        
    
    ZwavemodeHandler_set_zwavemode_current_state(thiz->zwavemode_state_machine,state);        
}

static void handle_zwavemode_STATE_INCLUSION_EVT_STATE_SYSTEM_CLEARING(State_zwavemode *thiz)
{    
    State_zwavemode *state = ZwavemodeHandler_get_zwavemode_STATE_SYSTEM_CLEARING(thiz->zwavemode_state_machine);
    
    if(DEBUG_MODE)
    {
        //printf("\n%s", __func__);
    }        
    
    ZwavemodeHandler_set_zwavemode_current_state(thiz->zwavemode_state_machine,state);        
}


static void handle_zwavemode_STATE_INCLUSION_house_keeping(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);
}

static void handle_zwavemode_STATE_INCLUSION_button_released(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);            

    
    // after button release timer should be off    
    thiz->zwavemode_state_machine->zwavemode_sw_timer_stop(thiz->zwavemode_state_machine->zwavemode_sw_timer_object);

    printf("\nHere inclusion code should be execute\n\n");    
    
    handle_zwavemode_STATE_INCLUSION_EVT_STATE_INCLUSION_EXECUTE(thiz);    
}

int callback_zwavemode_STATE_INCLUSION_timer_time_out(void *data)
{   
    State_zwavemode *state = (State_zwavemode *)data;
      
    if(state->handle_EVT_TIMER_TIME_OUT != NULL)
    {
        //printf("\n%s",__func__); 
        state->handle_EVT_TIMER_TIME_OUT(state);
    }    
    
    return 0;
}

static void handle_zwavemode_STATE_INCLUSION_entry(State_zwavemode *thiz)
{
    #define INCLUSION_TO_SYSTEMCLEAR_TIMEOUT   3000
    
    zwavemode_sw_timer_handle timer_hnd;
    //LED_Command led_cmd = {LED_EVENT_START,LED_INCLUSION_STATE};
    
    //printf("\n%s",__func__);  

    // feed led pattern 
    //LED_app_set_led_pattern(led_cmd);

    // on entry timer should be updated
    timer_hnd = thiz->zwavemode_state_machine->zwavemode_sw_timer_create(
                                                                            INCLUSION_TO_SYSTEMCLEAR_TIMEOUT,
                                                                            callback_zwavemode_STATE_INCLUSION_timer_time_out, 
                                                                            thiz->zwavemode_state_machine->zwavemode_sw_timer_object,
                                                                            (void*) thiz
                                                                        );
    if(thiz->zwavemode_state_machine->zwavemode_sw_timer_start(timer_hnd) == 0)
    {
        //error
    }
}

static void handle_zwavemode_STATE_INCLUSION_exit(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);
}

static State_zwavemode zwavemode_state = 
{
    .house_keeping                  = handle_zwavemode_STATE_INCLUSION_house_keeping,
    .handle_EVT_BUTTON_RELEASED     = handle_zwavemode_STATE_INCLUSION_button_released,
    .handle_EVT_TIMER_TIME_OUT      = handle_zwavemode_STATE_INCLUSION_EVT_STATE_SYSTEM_CLEARING,
    .entry                          = handle_zwavemode_STATE_INCLUSION_entry,
    .exit                           = handle_zwavemode_STATE_INCLUSION_exit,
};

State_zwavemode* get_zwavemode_STATE_INCLUSION(){ return &zwavemode_state;}

/**========================================    INCLUSION STATE END    ================================================**/



/**========================================    INCLUSION EXECUTE STATE    ================================================**/

static void handle_zwavemode_STATE_INCLUSION_EXECUTE_EVT_STATE_NORMAL(State_zwavemode *thiz)
{    
    State_zwavemode *state = ZwavemodeHandler_get_zwavemode_STATE_NORMAL(thiz->zwavemode_state_machine);
    
    if(DEBUG_MODE)
    {
        //printf("\n%s", __func__);
    }        
    
    ZwavemodeHandler_set_zwavemode_current_state(thiz->zwavemode_state_machine,state);        
}


static void handle_zwavemode_STATE_INCLUSION_EXECUTE_house_keeping(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);
}

static void handle_zwavemode_STATE_INCLUSION_EXECUTE_entry(State_zwavemode *thiz)
{
    //LED_Command led_cmd = {LED_EVENT_START,LED_INCLUSION_EXECUTE_STATE};
    
    //printf("\n%s",__func__);  

    // feed led pattern 
    //LED_app_set_led_pattern(led_cmd);
    
    handle_zwavemode_STATE_INCLUSION_EXECUTE_EVT_STATE_NORMAL(thiz);    // after enter in inclusion_execute mode inclusion_execute code should be execute then enter in normal mode (as we don't have inclusion_execute code then we are directly entering in normal mode).
}

static void handle_zwavemode_STATE_INCLUSION_EXECUTE_exit(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);
}

static State_zwavemode zwavemode_state_execute = 
{
    .house_keeping      = handle_zwavemode_STATE_INCLUSION_EXECUTE_house_keeping,
    .entry              = handle_zwavemode_STATE_INCLUSION_EXECUTE_entry,
    .exit               = handle_zwavemode_STATE_INCLUSION_EXECUTE_exit,   
};

State_zwavemode* get_zwavemode_STATE_INCLUSION_EXECUTE(){ return &zwavemode_state_execute;}

/**========================================    INCLUSION EXECUTE STATE END    ================================================**/