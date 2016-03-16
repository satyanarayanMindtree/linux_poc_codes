/*
 * Variable naming standard
 * Global = VariableName
 * Local = variable_name
 * Global_static = VariableName__
 * Local_static = variable_name__
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <pthread.h>
#include <execinfo.h>

pthread_mutex_t Lock;

# define LEN_OF_ARRAY(X)        sizeof(X)/sizeof(X[0])

static char TerminateFlag__ = 0;

void print_help (void) {
    printf ("\n\nUsage:: \t$ ./daemon_app daemon 0/1");
    printf ("\n\t\t1:: start with daemon service");
    printf ("\n\t\t0:: start as normal service\n\n");
    
    exit (0);
}

void sigint_handler (int signal_recieved) {
    
    printf ("\nTerminating Daemon Service with signal: %d \nPlease Wait !!!!!", signal_recieved);
    
    TerminateFlag__ = 0x00;
}

void sigsegfault_handler (int signal_recieved) {

    printf ("\nSegfault: Rebooting System Please Wait !!!!!");
    
    TerminateFlag__ = 0x00;
}

int main (int argc, char **argv) {
    int return_value = 0x00;
    int current_pid = 0x00;
    int sid = 0x00;
    int daemonize = 1;
    int option = 0x00;
    struct sigaction sigIntHandler, sigSegfault;

    sigIntHandler.sa_handler = sigint_handler;
    sigemptyset (&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction (SIGINT, &sigIntHandler, NULL);
    sigaction (SIGTERM, &sigIntHandler, NULL);

    sigSegfault.sa_handler = sigsegfault_handler;
    sigemptyset (&sigSegfault.sa_mask);
    sigSegfault.sa_flags = 0;
    sigaction (SIGSEGV, &sigSegfault, NULL);
    
    TerminateFlag__  = 0x01;
   
    if (argc == 3) {
        if (0 == strcmp (argv[1],"daemon")) {
            option = atoi (argv[2]);
            if (option != 0 && option != 1) {
                
                printf ("\nERROR:: incorrect command");
                    
                print_help ();
            }
            else {
                
                switch (option) {
                    
                    case 0:
                        daemonize =  0;
                        break;
                    case 1:
                        daemonize =  1;
                        break;
                } 
            }
        }
        else {                
                printf ("\nERROR:: incorrect command");
                    
                print_help ();
        }
    }    
    else {                
        printf ("\nERROR:: incorrect command");
            
        print_help ();
    }
    
    // Daemonising process
    if (daemonize == 1)
    {
        // Create child process
        return_value = fork ();
        
        // Indication of fork() failure
        if (return_value < 0)
        {
            printf ("\nERROR:: Fork failure");
            exit (1);
        }
        
        // PARENT PROCESS. Need to kill it.
        if (return_value > 0)
        {
            exit (0);
        }
        
        //unmask the file mode
        umask (0);
        
        //set new session
        sid = setsid ();
        if (sid < 0)
        {
            // Return failure
            exit (1);
        }
        
        // Change the current working directory to root.
        chdir ("/");
        
        // Close stdin. stdout and stderr
        /*
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
        */
    }
    
    current_pid = getpid ();
    
    printf ("\nService Running with PID:: %d !!!", current_pid);
    
    while (TerminateFlag__)
    {
        sleep (2);
        printf ("\nService Running ...");
    }

    
    printf ("\nService Terminated !!!\n\n");
    return 0;
}
