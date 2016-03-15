
/*******************************************************************************
*
*                           CIRCULAR BUFFER TEST PROGRAM
*
*******************************************************************************/


/*******************************************************************************
*                                 INCLUDE FILES
*******************************************************************************/


#include <stdio.h>
#include <assert.h>


#ifdef __unix__
#include "cbuff.h"
#endif
/*******************************************************************************
*                                 LOCAL DEFINES
*******************************************************************************/
#define INBUFFERSIZE        1000
#define OUTBUFFERSIZE       32
#define TESTBUFFER1SIZE     8
#define TESTBUFFER2SIZE     16


static CBUFF                inBuffer[INBUFFERSIZE];
static CBUFF                outBuffer[OUTBUFFERSIZE];
static CBUFF                testBuffer1[TESTBUFFER1SIZE];
static CBUFF                testBuffer2[TESTBUFFER2SIZE];
static CBUFFOBJ             inBufferObj;
static CBUFFOBJ             outBufferObj;
static CBUFFOBJ             testBuffer1Obj;
static CBUFFOBJ             testBuffer2Obj;


int main(void)

{
    CBUFF               writeData = 0;
    CBUFF               readData = 0;
    unsigned char       x;              /* used for 'for' loops               */
    unsigned char       y;
    unsigned int        spaceRemainingInBuffer = 0;
    unsigned int        dataInBuffer = 0;
    CBUFFNUM            inBufferNum;
    CBUFFNUM            outBufferNum;
    CBUFFNUM            testBuffer1Num;
    CBUFFNUM            testBuffer2Num;
    HCBUFF              hInBuffer;
    HCBUFF              hOutBuffer;
    HCBUFF              hDummyHandle;
    
    CBUFFOBJ            newCircBufferObj;
    
    int                 i = 0, k = 0, count;
    
#define MY_BUF_SIZE   1000
    
    CBUFF               buf[MY_BUF_SIZE] = {0};


                                        /* Initialise buffer module           */
    cbuffInit();

    printf("Initiasing Circular buffer of size 1000 bytes\n");
    
    inBufferNum = cbuffCreate(inBuffer, INBUFFERSIZE,&inBufferObj);
    
    hInBuffer = cbuffOpen(inBufferNum);
    
    printf("Writing 999 bytes \n");
    count  = cbuffPutArray(hInBuffer, buf, 999);
    printf("Successfully wrote %d bytes \n", count);
    
    printf("Reading 500 bytes \n");
    count  = cbuffGetArray(hInBuffer, buf, 500);
    printf("Successfully read %d bytes \n", count);
    
    printf("Reading 500 bytes \n");
    count  = cbuffGetArray(hInBuffer, buf, 500);
    printf("Could not read 500 byte. Read only  %d bytes \n", count);
    
    
    printf("Writing 500 bytes \n");
    count  = cbuffPutArray(hInBuffer, buf, 500);
    printf("Successfully wrote %d bytes \n", count);
    
    /*No free space is available*/
    printf("Writing 700 bytes \n");
    count  = cbuffPutArray(hInBuffer, buf, 700);
    printf("Could not wrote 700. wrote only %d bytes \n", count);
    
    return 0;
}

/*******************************************************************************
*
*                           CIRCULAR BUFFER MODULE END
*
*******************************************************************************/
