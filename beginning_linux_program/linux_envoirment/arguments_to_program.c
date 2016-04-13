#include<stdio.h>

int main (int argc, char *argv[]) {

    int counter = 0x00;

    for ( counter = 0x00; counter  <  argc; counter ++) {
            printf( "\nArgument:: %d ==> %s ", counter, argv[counter]);

    }

    printf ("\n");
    return 0;
}
