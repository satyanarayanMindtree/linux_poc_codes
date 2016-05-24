#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

// Reading Output from an External Program

int main()
{
    FILE *read_fp;
    char buffer[BUFSIZ + 1] = {0};
    int chars_read = 0x00;
    
    memset (buffer, '\0', sizeof(buffer));
    
    read_fp = popen ("uname -a", "r");
    if (read_fp != NULL) {
        chars_read = fread (buffer, sizeof(char), BUFSIZ, read_fp);
        if (chars_read > 0) {
            printf("Output was:-\n%s\n", buffer);
        }
        pclose (read_fp);
        exit (EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}