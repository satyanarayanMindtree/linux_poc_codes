#if 0

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    int opt;
    while ((opt = getopt (argc, argv, "if:l:r:")) != -1) {
        switch (opt) {
            case 'i':
            case 'l':
            case 'r':
                printf ("option:: %c optarg:: %s\n", opt, optarg);
                break;
            case 'f':
                printf ("option:: %c optarg:: %s\n", opt, optarg);
                break;
            case ':':
                printf ("option needs a value\n");
                break;
            case '?':
                printf ("unknown option: %c\n", optopt);
                break;
        }
    }
    for (; optind < argc; optind++) {
        printf ("argument: %s %d\n", argv[optind], optind);
    }
    exit(0);
}

/* Testing above code 
 * 
 * as option i dont have optarg (i.e. ":")
$ ./a.out -i iiiii -l lllll -r rrrrr -f fffff -q qqqqq
$ 
option:: i optarg:: (null)
option:: l optarg:: lllll
option:: r optarg:: rrrrr
option:: f optarg:: fffff
./a.out: invalid option -- 'q'
unknown option: q
argument: iiiii 9
argument: qqqqq 10

*/
#endif


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <getopt.h>

int main (int argc, char *argv[]) {
    
    int opt;
    struct option longopts[] = {
        {"initialize", 0, NULL, 'i'},
        {"file", 1, NULL, 'f'},
        {"list", 0, NULL, 'l'},
        {"restart", 0, NULL, 'r'},
        {0,0,0,0}        
    };
    while ((opt = getopt_long(argc, argv, ":if:lr", longopts, NULL)) != -1) {
        switch (opt) {
            case 'i':
            case 'l':
            case 'r':
                printf ("option:: %c optarg:: %s\n", opt, optarg);
                break;
            case 'f':
                printf ("option:: %c optarg:: %s\n", opt, optarg);
                break;
            case ':':
                printf ("option needs a value\n");
                break;
            case '?':
                printf ("unknown option: %c\n", optopt);
                break;
        }
    }

    for (; optind < argc; optind++) {
        printf("argument: %s\n", argv[optind]);
    }
    
    exit(0);
   
}


/* Testing above code
 * 
$ ./a.out --init -l --file=fred.c ‘hi there’
option:: i optarg:: (null)
option:: l optarg:: (null)
option:: f optarg:: fred.c
argument: ‘hi
argument: there’
*/