#ifndef __system_time_h__
#define __system_time_h__

#include <stdio.h>
#include <sys/time.h>
#include<time.h>

time_t system_time_ms (void);
time_t system_time_sec (void);

#endif