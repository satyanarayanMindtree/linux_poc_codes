/* Usage
#include <syslog.h>
void syslog(int priority, const char *message, arguments...);

    Priority Level          Description
    LOG_EMERG               An emergency situation
    LOG_ALERT               High-priority problem, such as database corruption
    LOG_CRIT                Critical error, such as hardware failure
    LOG_ERR                 Errors
    LOG_WARNING             Warning
    LOG_NOTICE              Special conditions requiring attention
    LOG_INFO                Informational messages
    LOG_DEBUG               Debug messages
    
*/

#include <syslog.h>
#include <stdio.h>
#include <stdlib.h>
int main () {
    FILE *f;
    f = fopen ("not_here","r");
    if (!f) {
        // The specifier %m may be used to insert the error message string associated with the current value of the error variable, errno . 
        //This can be useful for logging error messages.
        syslog (LOG_ERR|LOG_USER,"oops - %m\n");
    }
    exit (0);
}