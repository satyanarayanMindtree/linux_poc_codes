#include<zwavemode_operation_pvt.h>


/**========================================    FAULTY STATE    ================================================**/

static void handle_zwavemode_STATE_FAULTY_house_keeping(State_zwavemode *thiz)
{
    //printf("\n%s",__func__);
}

static void handle_zwavemode_STATE_FAULTY_entry(State_zwavemode *thiz)
{
    //LED_Command led_cmd = {LED_EVENT_START,LED_FAULTY_STATE};
    
    //printf("\n%s",__func__);  

    // feed led pattern 
    //LED_app_set_led_pattern(led_cmd);
}


static State_zwavemode zwavemode_state = 
{
    .house_keeping      = handle_zwavemode_STATE_FAULTY_house_keeping,
    .entry              = handle_zwavemode_STATE_FAULTY_entry,        
};

State_zwavemode* get_zwavemode_STATE_FAULTY(){ return &zwavemode_state;}

/**========================================    FAULTY STATE END    ================================================**/