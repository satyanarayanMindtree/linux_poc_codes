
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef _SW_TIMER_H
#define _SW_TIMER_H //{

#ifdef __cplusplus 
extern "C"
{
#endif
typedef int (*cb_func_ptr)(void*);

typedef void* sw_timer_handle;

typedef struct __sw_timer sw_timer;

typedef enum __timer_state
{
    TIMER_STATE_IDLE,
    TIMER_STATE_RUNNING,
    TIMER_STATE_HALT,
    TIMER_STATE_STOPPED
}timer_state;


struct __sw_timer
{
    int time_out;                                   /**< granularity of 1 sec */
    long int start_time;                            /**< time when timer was triggered */                                 
    cb_func_ptr cb_func_ptr_on_time_out;            /**< pointer to callback function */
    void* data;                                     /**< pointer to data that need to be passed to callback function as param */                                 
    sw_timer* next;                                 /**< pointer to next node in linked list */
    timer_state state;                              /**<  state of the timer */
};




#define SW_TIMER_TIMEOUT_10_SEC  (10)

#define SW_TIMER_TIMEOUT_5_SEC   (5)

#define SW_TIMER_TIMEOUT(sec)    (sec)

/**
 * @brief: initialises the software timer module
 *
 * @return O for success or error code
 */
int sw_timer_init(void);


int sw_timer_term(void);

/**
 * @brief: creates software timer. 
 * @param[in] timeout  timeout of the timer in msec
 * @param[in] cb_func_ptr_on_time_out  pointer to function that needs to be called after timeout
 * @param[in] data data to be passed to registered callback function.
 *
 * @return sw_timer_handle for success or NULL on error.
 */
sw_timer_handle sw_timer_create(int timeout_ms, cb_func_ptr cb_func_ptr_on_time_out, sw_timer *timer,void* data);


/**
 * @brief: starts software timer.
 * @param[in] timer_hnd  handle of the timer
 *
 * @return 0 for success or -1 on error.
 */
int sw_timer_start(sw_timer_handle timer_hnd);

/**
 * @brief: stops software timer.
 * @param[in] timer_hnd  handle of the timer
 *
 * @return 0 for success or -1 on error.
 */
int sw_timer_stop(sw_timer_handle timer_hnd);



#ifdef __cplusplus 

}
#endif

#endif // } _SW_TIMER_H
