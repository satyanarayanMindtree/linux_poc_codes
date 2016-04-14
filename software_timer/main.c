

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>

#include"sw_timer.h"

#define MAX_TIMER_OBJ 10

/*
 * Variable naming standard
 * Global = VariableName
 * Local = variable_name
 * Global_static = VariableName__
 * Local_static = variable_name__
 */

static u8 TerminateFlag__ = 0x00;

void *TimerObjAaray[MAX_TIMER_OBJ];

void *callback_function (void * arg) {
 
//     printf ("\nFunction:: %s %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%", __func__);
    char command[100];

    sprintf(command, "\necho \"%lu\" >> /tmp/sw_timer_test", (long unsigned int )arg);
    system(command);
    return NULL;
}

int get_empty_timer_obj (void) {
    int timer_obj = 0x00;
    for( timer_obj = 0x00; timer_obj < MAX_TIMER_OBJ; timer_obj++) {
        if (TimerObjAaray[timer_obj] == NULL)
            break;
    }    
    if (timer_obj >= MAX_TIMER_OBJ)
        return -1;
    else 
        return timer_obj;   
}

int main (int argc, char **argv)
{    
    int choice = 0x00;
    char input[20] = {0};
    
    printf ("\nPID:: %d", getpid());
    
    sw_timer_init ();
    
    TerminateFlag__ = 0x01;
    
    while (TerminateFlag__) {
        printf ("\n1.Creat sw_timer\n2.Start sw_timer\n3.Stop sw_timer\n4.Delete sw_timer\n5.Exit");
        printf ("\nEnter your choice:: ");
        
        memset (input, 0x00, sizeof(input));
        fgets (input, sizeof(input), stdin);
        choice = atoi (input);

        switch (choice) {
            case 1:
                {
                    int timer_timeout = 0x00;
                    int timer_obj = 0x00;
                    
                    printf ("\nEnter timer_timeout:: ");
                    memset (input, 0x00, sizeof(input));
                    fgets (input, sizeof(input), stdin);
                    timer_timeout = atoi (input);

                    timer_obj = get_empty_timer_obj ();
                    if (timer_obj != -1) {
                        sw_timer_get_timer_object (&TimerObjAaray[timer_obj], timer_timeout, callback_function, &TimerObjAaray[timer_obj]);    
                    }                
                }
                break;
            case 2:
                {
                    int timer_obj = 0x00;
                    
                    printf ("\nEnter timer_obj:: ");
                    memset (input, 0x00, sizeof(input));
                    fgets (input, sizeof(input), stdin);
                    timer_obj = atoi (input);

                    if ((timer_obj < MAX_TIMER_OBJ) && (TimerObjAaray[timer_obj] != NULL)) {
                        sw_timer_start (TimerObjAaray[timer_obj]);    
                    }          
                }
                break;
            case 3:
                {
                    int timer_obj = 0x00;
                    
                    printf ("\nEnter timer_obj:: ");
                    memset (input, 0x00, sizeof(input));
                    fgets (input, sizeof(input), stdin);
                    timer_obj = atoi (input);
                   
                    if ((timer_obj < MAX_TIMER_OBJ) && (TimerObjAaray[timer_obj] != NULL)) {
                        sw_timer_stop (TimerObjAaray[timer_obj]);    
                    }          
                }
                break;
            case 4:
                {
                    int timer_obj = 0x00;
                    
                    printf ("\nEnter timer_obj:: ");
                    memset (input, 0x00, sizeof(input));
                    fgets (input, sizeof(input), stdin);
                    timer_obj = atoi (input);
                   
                    if ((timer_obj < MAX_TIMER_OBJ) && (TimerObjAaray[timer_obj] != NULL)) {
                        sw_timer_delete (TimerObjAaray[timer_obj]);    
                        TimerObjAaray[timer_obj] = NULL;
                    }          
                }
                break;
            case 5:
            {
                TerminateFlag__ = 0x00;
                printf ("\nTerminating Program");
            }
            break;
        
        }
    }
    
    sw_timer_term ();
    
    printf ("\nProcesss Terminated ########################\n");
    printf("\n");
    
    return 0;
}