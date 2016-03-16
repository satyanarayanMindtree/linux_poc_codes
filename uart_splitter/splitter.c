/*
***************************************************************************
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation version 2 of the License.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*
***************************************************************************
*
* This version of GPL is at http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt
*
***************************************************************************
*/

#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "rs232.h"

#include <string.h>


/*

one physical port
n application psudo port
m sniffer port

pasrse command line args

- open physical port
- open virtual ports

while(1)
{
    read physical port and write to all virtual ports
    
    read from all application ports and write to physical port
    
    no need to read sniffer ports
}

*/


static char *physical_port_file = "/dev/ttymxc3";

static char *app_virtual_port_file[] = {
    "/dev/pts/0",
};

static char *sniffer_port_file[] = {
    "/dev/pts/3",
};

static unsigned char rx_phy_buf[4096];

int main(int argc, char *argv[])
{
    int i, n,
        physical_port=0,        /* /dev/ttyS0 (COM1 on windows) */
        bdrate=115200;       /* 9600 baud */
        
    int *app_port = NULL;
    int app_virtual_port_count = 0;
    
    int *sniffer_port = NULL;
    int sniffer_virtual_port_count = 0;

    

    physical_port = RS232_OpenComport(physical_port_file, bdrate);

    if(physical_port < 0 )
    {
        printf("Can not open physical_port\n");

        return(0);
    }
    
    sniffer_virtual_port_count = sizeof(sniffer_port_file)/sizeof(char*);
    
    sniffer_port = malloc(sizeof(int)*sniffer_virtual_port_count);
    
    for(i = 0; i < sniffer_virtual_port_count; i++)
    {
        sniffer_port[i] = RS232_OpenComport(sniffer_port_file[i], bdrate);
        if(sniffer_port[i] < 0 )
        {
            printf("Can not open sniffer_port\n");

            return(0);
        }
    }
    
    app_virtual_port_count = sizeof(app_virtual_port_file)/sizeof(char*);
    
    app_port = malloc(sizeof(int)*app_virtual_port_count);
    
    for(i = 0; i < app_virtual_port_count; i++)
    {
        app_port[i] = RS232_OpenComport(app_virtual_port_file[i], bdrate);
        if(app_port[i] < 0 )
        {
            printf("Can not open app_port\n");

            return(0);
        }
    }

    while(1)
    {
        n = RS232_PollComport(physical_port, rx_phy_buf, sizeof(rx_phy_buf));

        if(n > 0)
        {
            rx_phy_buf[n] = 0;   /* always put a "null" at the end of a string! */


            printf("received %i bytes:\n", n);
            
            /*send data to sniffer*/
            for(i = 0; i < sniffer_virtual_port_count; i++)
            {
                RS232_SendBuf(sniffer_port[i], rx_phy_buf, n);
            }
            
            /*send data to app port*/
            for(i = 0; i < app_virtual_port_count; i++)
            {
                RS232_SendBuf(app_port[i], rx_phy_buf, n);
            }
            
        }
        
        /*read data from app port*/
        for(i = 0; i < app_virtual_port_count; i++)
        {
            n = RS232_PollComport(app_port[i], rx_phy_buf, sizeof(rx_phy_buf));
            if(n > 0)
            {
                RS232_SendBuf(physical_port, rx_phy_buf, n);
            }
        }
        

    #ifdef _WIN32
        Sleep(100);
    #else
        usleep(100000);  /* sleep for 100 milliSeconds */
    #endif
    }

    return(0);
}

