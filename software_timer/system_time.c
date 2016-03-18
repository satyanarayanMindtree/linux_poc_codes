
#include"system_time.h"

long long system_time (void) {
    static long long time_t0 = 0;
    long long temp_time = 0;
    long long cur_time;
    struct timespec current;
    
    clock_gettime (CLOCK_MONOTONIC, &current);
  
    //get time in  ns
    temp_time = current.tv_sec * 1000;
    temp_time = (temp_time  + current.tv_nsec / 1000000);

    if (time_t0 == 0) {

        time_t0 =  temp_time;
        return 0;
    }
    else {
        cur_time = (temp_time - time_t0);
        return cur_time;
    }
}

time_t system_time_ms (void) {
    return system_time ();
}

time_t system_time_sec (void) {
    return (system_time () / 1000);
}
