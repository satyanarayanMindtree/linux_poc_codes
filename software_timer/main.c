

#include <stdio.h>
#include <unistd.h>
#include <signal.h>


#include"sw_timer.h"

/*
 * Variable naming standard
 * Global = VariableName
 * Local = variable_name
 * Global_static = VariableName__
 * Local_static = variable_name__
 */

static u8 TerminateFlag__ = 0x00;

void *timer_obj = NULL;
void *timer_obj_1 = NULL;

void *callback_function (void * arg) {
 
    printf ("\nFunction:: %s %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%", __func__);
    
    return NULL;
}

void *callback_function_1 (void * arg) {
 
    printf ("\nFunction:: %s %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%", __func__);
    
    return NULL;
}

void sigint_handler (int signal_recieved) {

    printf ("\nDeleting timer !!!!!!!");
//     sw_timer_update(timer_obj, 5, callback_function_1, NULL);    
    sw_timer_delete(timer_obj);
    
}

void sigterm_handler (int signal_recieved) {

    printf ("\nStarting timer !!!!!!!");
    sw_timer_start(timer_obj);
    
}

int main (int argc, char **argv)
{
    struct sigaction sigIntHandler, sigTermHandler;

    sigIntHandler.sa_handler = sigint_handler;
    sigemptyset (&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction (SIGINT, &sigIntHandler, NULL);

    sigTermHandler.sa_handler = sigterm_handler;
    sigemptyset (&sigTermHandler.sa_mask);
    sigTermHandler.sa_flags = 0;
    sigaction (SIGTERM, &sigTermHandler, NULL);

    
    printf ("\nPID:: %d", getpid());
    
    sw_timer_init ();
    
    sw_timer_get_timer_object(&timer_obj, 5, callback_function, NULL);    
    sw_timer_get_timer_object(&timer_obj_1, 2, callback_function_1, NULL);    
    
    sw_timer_start(timer_obj);
    sw_timer_start(timer_obj_1);
    printf ("\nStarted timer !!!!!!!");
    
    TerminateFlag__ = 0x01;
    
    while (TerminateFlag__) {
        printf ("\n Going for sleep ..."); 
        sleep(1);
    }
    
    sw_timer_term ();
    
    printf ("\nProcesss Terminated ########################\n");
    printf("\n");
    
    return 0;
}