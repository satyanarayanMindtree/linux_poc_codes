#ifndef __sw_timer_h__
#define __sw_timer_h__

#include "datatypes.h"

s8 sw_timer_init (void);
s8 sw_timer_term (void);

s8 sw_timer_get_timer_object (void **user_timer_object, u32 timer_time_out, void *callback_func, void *callback_arg);

s8 sw_timer_start (void **user_timer_object);
s8 sw_timer_stop (void *user_timer_object);
s8 sw_timer_delete (void *user_timer_object);

s8 sw_timer_reload (void *user_timer_object, u32 timer_time_out);
s8 sw_timer_update (void *user_timer_object, u32 timer_time_out, void *callback_func, void *callback_arg);

s8 sw_timer_restart (void *user_timer_object);


#endif

