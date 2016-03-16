#include<zwavemode_operation_pvt.h>


/**========================================    NORMAL STATE    ================================================**/

static void handle_zwavemode_STATE_NORMAL_EVT_STATE_INCLUSION(State_zwavemode *thiz)
{
    State_zwavemode *state = ZwavemodeHandler_get_zwavemode_STATE_INCLUSION(thiz->zwavemode_state_machine);
    if(DEBUG_MODE)
    {
        //printf("\n%s", __func__);
    }        
    ZwavemodeHandler_set_zwavemode_current_state(thiz->zwavemode_state_machine,state);        
}


static void handle_zwavemode_STATE_NORMAL_house_keeping(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);
}

static void handle_zwavemode_STATE_NORMAL_button_released(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);            
    
    thiz->zwavemode_state_machine->zwavemode_sw_timer_stop(thiz->zwavemode_state_machine->zwavemode_sw_timer_object);    
}

int callback_zwavemode_STATE_NORMAL_timer_time_out(void *data)
{   
    State_zwavemode *state = (State_zwavemode *)data;

    if(state->handle_EVT_TIMER_TIME_OUT != NULL)
    {
        //printf("\n%s",__func__); 
        state->handle_EVT_TIMER_TIME_OUT(state);
    }    
    
    return 0;
}
static void handle_zwavemode_STATE_NORMAL_button_press(State_zwavemode *thiz)
{
    #define NORMAL_TO_INCLUSION_TIMEOUT    3000
    
    zwavemode_sw_timer_handle timer_hnd;
    
    //printf("\n%s\n",__func__);            

    // on button_press timer should be updated
    timer_hnd = thiz->zwavemode_state_machine->zwavemode_sw_timer_create(
                                                                            NORMAL_TO_INCLUSION_TIMEOUT,
                                                                            callback_zwavemode_STATE_NORMAL_timer_time_out, 
                                                                            thiz->zwavemode_state_machine->zwavemode_sw_timer_object,
                                                                            (void*) thiz
                                                                        );
    if(thiz->zwavemode_state_machine->zwavemode_sw_timer_start(timer_hnd) == 0)
    {
        //error
    }         
}


static void handle_zwavemode_STATE_NORMAL_entry(State_zwavemode *thiz)
{
    //LED_Command led_cmd = {LED_EVENT_START,LED_NORMAL_STATE};
    
    //printf("\n%s",__func__);  

    // feed led pattern 
    //LED_app_set_led_pattern(led_cmd);
}

static void handle_zwavemode_STATE_NORMAL_exit(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);         
}

static State_zwavemode zwavemode_state = 
{
    .house_keeping                  = handle_zwavemode_STATE_NORMAL_house_keeping,
    .handle_EVT_TIMER_TIME_OUT      = handle_zwavemode_STATE_NORMAL_EVT_STATE_INCLUSION,
    .handle_EVT_BUTTON_RELEASED     = handle_zwavemode_STATE_NORMAL_button_released,
    .handle_EVT_BUTTON_PRESSED      = handle_zwavemode_STATE_NORMAL_button_press,
    .entry                          = handle_zwavemode_STATE_NORMAL_entry,    
    .exit                           = handle_zwavemode_STATE_NORMAL_exit,
};

State_zwavemode* get_zwavemode_STATE_NORMAL(){ return &zwavemode_state;}

/**========================================    NORMAL STATE END    ================================================**/
