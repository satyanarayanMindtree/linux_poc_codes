#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(void)
{
    int int_value = 0x00;
    char buffer[50] = "123456";
    FILE *fp = NULL;    
    int flag_value = 0x00;
    char buffer_new[50] = "123456";
    while(1)
    {
        fp = fopen("/tmp/upstart_flag", "r");
        if(fp == NULL)
        {
            printf("\nERROR:: file opening");  
            sleep(5);
            continue;
        }
        else
        {            
            fscanf(fp,"%d",&flag_value);
            printf("\nflag_value: %d", flag_value);
            fclose(fp);
        }

        
        if (flag_value != 0)
        {
            memset(buffer, 0x00, sizeof(buffer));
        }
        else
        {
            memcpy(buffer, buffer_new, sizeof(buffer));
        }
        int_value = atoi(strtok(buffer,"\t"));        
        printf("\nint_value: %d\n", int_value);\
        sleep(10);
    }
}


