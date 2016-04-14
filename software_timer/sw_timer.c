

#include "sw_timer_pvt.h"
#include "system_time.h"
#include <pthread.h>
#include <unistd.h>
#include <signal.h>

#define SW_TIMER_PROCESS_SLEEP 100*1000

static u8 TerminateFlag__ = 0x00;
static SW_TIMER *SwTimerListHead__ = NULL;
static pthread_t SwTimerThread__;

void *sw_timer_process_thread (void *param) {
    
    SW_TIMER *travel_list = NULL;
    u32 current_system_time = 0x00;
    u32 retval = 0x00;
    
    while (TerminateFlag__) {
        
        travel_list = SwTimerListHead__;
        while (travel_list != NULL) {                 
           
            if (travel_list->state == TIMER_RUNNING) {
                
                current_system_time = system_time_sec ();
                if (current_system_time >= (travel_list->timer_start_time + travel_list->timer_timeout)) {
               
                    travel_list->state = TIMER_IDLE;
                    
                    retval = pthread_create(&travel_list->sw_thread, NULL, travel_list->callback_function, travel_list->callback_argument);
                    if (retval != 0x00) {
                        return NULL;
                    }
                }
            }            
            travel_list = travel_list->next;            
        }
        
        // Sleep for few ms
//         usleep(SW_TIMER_PROCESS_SLEEP);
    }
    
    return NULL;
}

s8 sw_timer_init (void) {
    
    TerminateFlag__ = 0x00;
    SwTimerListHead__ = NULL;
    
    return 0;
}

s8 sw_timer_term (void) {
    
    SW_TIMER *timer_object = NULL;

    // Terminate SwTimerThread__
    TerminateFlag__ = 0x00;
    pthread_join(SwTimerThread__, NULL);
    
    // free all registered sw_timer objects
    timer_object = SwTimerListHead__;
    
    while (timer_object != NULL) {     
        pthread_kill(timer_object->sw_thread, SIGKILL);
        free(timer_object);
        timer_object = timer_object->next;
    }
    
    SwTimerListHead__ = NULL;
    
    return 0;
}

s8 sw_timer_get_timer_object (void **user_timer_object, u32 timer_time_out, void *callback_func, void *callback_arg) {
    
    SW_TIMER *timer_object = NULL;
    
    if ((callback_func == NULL) || (timer_time_out == 0x00))
        return -2;

    timer_object = (SW_TIMER *) malloc (sizeof (SW_TIMER));    
    if (timer_object == NULL)
        return -1;
       
    timer_object->timer_timeout = timer_time_out;
    timer_object->callback_function = callback_func;
    timer_object->callback_argument = callback_arg;
    timer_object->state = TIMER_IDLE;
    timer_object->timer_start_time = 0x00;
    timer_object->next = NULL;
    *user_timer_object = (void *) timer_object;
    

    return 0;
}

static s8 sw_timer_object_validate_register (SW_TIMER *user_timer_object) {
    SW_TIMER *travel_list = SwTimerListHead__;
    
    while (travel_list->next != NULL) {
        
        if (travel_list == user_timer_object)
            return 0;
    }
    
    return -1;
}

s8 sw_timer_start (void *user_timer_object) {
    
    SW_TIMER *timer_object = NULL;
    u32 retval = 0x00;    
    
    if (user_timer_object == NULL)
        return -2;

    timer_object = (SW_TIMER *) user_timer_object;   
    
    if (SwTimerListHead__ == NULL) {

        // Here we neeed to start SwTimerThread__
        TerminateFlag__ = 0x01;
        retval = pthread_create(&SwTimerThread__, NULL, sw_timer_process_thread, NULL);
        if (retval != 0x00) {
            return -1;
        }
        SwTimerListHead__ = timer_object;        
        
        timer_object->timer_start_time = system_time_sec ();
        // change state to TIMER_RUNNING
        timer_object->state = TIMER_RUNNING;
    }
    else {
        // check timer object already registered or not
        if (sw_timer_object_validate_register (timer_object) == 0) {
            timer_object->timer_start_time = system_time_sec ();
            // change state to TIMER_RUNNING
            timer_object->state = TIMER_RUNNING;        
        }
        else {
            // if not registered then register
            SW_TIMER *travel_list = SwTimerListHead__;
            
            while (travel_list->next != NULL) {
                
                travel_list = travel_list->next;
            }
            
            travel_list->next = timer_object;        
            timer_object->timer_start_time = system_time_sec ();
            // change state to TIMER_RUNNING
            timer_object->state = TIMER_RUNNING;
        }
    }           

    return 0;
}


s8 sw_timer_reload (void *user_timer_object, u32 timer_time_out) {
    
    SW_TIMER *timer_object = NULL;
    SW_TIMER *travel_list = SwTimerListHead__;
    
    if (user_timer_object == NULL)
        return -2;

    timer_object = (SW_TIMER *) user_timer_object;   
    
    while (travel_list != timer_object) {
        
        travel_list = travel_list->next;
    }
    
    if (travel_list == timer_object) {
        
        travel_list->timer_timeout = timer_time_out;
        timer_object->state = TIMER_IDLE;
        
        return 0;
    }
    else {
        
        // on invalid user_timer_object
        return -2;
    }
}


s8 sw_timer_restart (void *user_timer_object) {
    
    SW_TIMER *timer_object = NULL;
    SW_TIMER *travel_list = SwTimerListHead__;
    
    if (user_timer_object == NULL)
        return -2;

    timer_object = (SW_TIMER *) user_timer_object;   
    
    if (SwTimerListHead__ == NULL)
    {
        return 0;
    } 
    
    while (travel_list != timer_object) {
        
        travel_list = travel_list->next;
    }
    
    if (travel_list == timer_object) {
       
        timer_object->timer_start_time = system_time_sec ();
        timer_object->state = TIMER_RUNNING;
        
        return 0;
    }
    else {
        
        // on invalid user_timer_object
        return -2;
    }
}


s8 sw_timer_stop (void *user_timer_object) {

    SW_TIMER *timer_object = NULL;
    SW_TIMER *travel_list = SwTimerListHead__;
    
    if (user_timer_object == NULL)
        return -2;

    timer_object = (SW_TIMER *) user_timer_object;   
    
    if (SwTimerListHead__ == NULL)
    {
        return 0;
    }  
    
    while (travel_list != timer_object) {
        
        travel_list = travel_list->next;
    }
    
    if (travel_list == timer_object) {
    
        // change timer state to TIMER_STOP
        travel_list->state = TIMER_STOP;

        return 0;
    }
    else {
        
        // on invalid user_timer_object
        return -2;
    }
}

s8 sw_timer_delete (void *user_timer_object) {

    SW_TIMER *timer_object = NULL;
    SW_TIMER *travel_list = SwTimerListHead__;
    
    if (user_timer_object == NULL)
        return -2;

    timer_object = (SW_TIMER *) user_timer_object;   

    if (SwTimerListHead__ == NULL)
    {
        // kill SwTimerThread__
        return 0;
    }    

    if (SwTimerListHead__ == timer_object) {
    
        SwTimerListHead__ = timer_object->next;        
        
        // delete timer object
        pthread_kill(timer_object->sw_thread, SIGKILL);
        free(timer_object);
        user_timer_object = NULL;        
    }
    else {
    
        while (travel_list->next != timer_object) {
            
            travel_list = travel_list->next;
        }
        
        if (travel_list->next == timer_object) {
            
            travel_list->next = timer_object->next;
            
            // delete timer object
            pthread_kill(timer_object->sw_thread, SIGKILL);
            free(timer_object);
            user_timer_object = NULL;
        }
        else {
            
            // on invalid user_timer_object
            return -2;
        }
    }
    
    return 0;
}


// s8 sw_timer_update (void *user_timer_object, u32 timer_time_out, void *callback_func, void *callback_arg) {
//     
//     SW_TIMER *timer_object = NULL;
//     SW_TIMER *travel_list = SwTimerListHead__;
//     
//     if (user_timer_object == NULL)
//         return -2;
// 
//     timer_object = (SW_TIMER *) user_timer_object;   
//     
//     while (travel_list != timer_object) {
//         
//         travel_list = travel_list->next;
//     }
//     
//     if (travel_list == timer_object) {
//         
//         timer_object->timer_timeout = timer_time_out;
//         timer_object->callback_function = callback_func;
//         timer_object->callback_argument = callback_arg;
//         timer_object->state = TIMER_IDLE;
//         timer_object->timer_start_time = 0x00;
//         
//         return 0;
//     }
//     else {
//         
//         // on invalid user_timer_object
//         return -2;
//     }    
// }