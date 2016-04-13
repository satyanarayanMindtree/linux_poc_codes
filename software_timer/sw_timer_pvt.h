#ifndef __SW_TIMER_pvt_h__
#define __SW_TIMER_pvt_h__

#include "datatypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef void * (*CALLBACK_FUNCTION) (void *);
typedef struct sw_timer SW_TIMER;

typedef enum timer_state {
    TIMER_IDLE,
    TIMER_RUNNING,
    TIMER_STOP,
} TIMER_STATE;

struct sw_timer {
    
    u32 timer_timeout;
    u32 timer_start_time;
    CALLBACK_FUNCTION callback_function;
    TIMER_STATE state;
    void *callback_argument;
    pthread_mutex_t timer_lock;
    struct sw_timer *next;
    pthread_t sw_thread;
};




#endif