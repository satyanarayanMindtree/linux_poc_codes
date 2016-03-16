   
#include <timer_pvt.h>
//#include <errorCode.h>

#ifdef __unix__

#include <pthread.h>
#include <sys/time.h>
#include <sys/timeb.h>
#include <assert.h>

#endif


/**
 * @brief: starts main timer thread
 * @param[in] void 
 * @return 0 on success or error code
 */
static int sw_timer_thread_start(void);

/**
 * @brief: deletes the node which has finished timer
 * @param[in] trav_list  timer node to be deleted
 * @return void 
 */
static void delete_timer_node(sw_timer *trav_list);

// this flag indicates if the timer module is intialised or not.
static int sw_timer_init_flag = 0;

static int sw_timer_run_flag = 0;

// pointer to the linked list head & list counter.
static sw_timer *sw_timer_ll_head = NULL;

#ifdef __unix__
static pthread_mutex_t sw_timer_ll_mutex;
static pthread_t timer_thread;
#endif


void* sw_timer_thread_proc(void* arg)
{    
    long int current_time;
    int success_callback        = 0;
    sw_timer *trav_list         = sw_timer_ll_head;
    sw_timer *trav_list_temp    = NULL; 
    
    struct timeb the_time;      // to read timer value in milli_seconds & seconds
    
    //printf("Main timer thread started !! \n");
    
    while(sw_timer_run_flag == 1)
    {
#ifdef __unix__
        pthread_mutex_lock(&sw_timer_ll_mutex);
#endif
        //  check the queue and if timeout occured then call callback function
        ////printf("traversing nodes !! \n");
        for(trav_list = sw_timer_ll_head; trav_list != NULL; trav_list = trav_list->next)
        {
            if(trav_list->state != TIMER_STATE_RUNNING)
            {
                continue;
            }

            //get the current times in milli_seconds
            ftime (&the_time);
            current_time = (the_time.time * 1000) + the_time.millitm;
            
            if(current_time > ( trav_list->start_time + trav_list->time_out) )
            {  
                sw_timer trav_list_callback; 
                
                // backup this sw timer object content to before delete
                trav_list_callback.cb_func_ptr_on_time_out  = trav_list->cb_func_ptr_on_time_out;
                trav_list_callback.data                     = trav_list->data;
                
                
                //delete the node                
                trav_list_temp = trav_list->next;
                delete_timer_node(trav_list);
                
                //call the callback function
                trav_list = &trav_list_callback;
                success_callback = (*trav_list->cb_func_ptr_on_time_out)(trav_list->data);
                if(success_callback == 0)
                {
                    ////printf("callback call successfull !! \n");
                }
                
                trav_list = trav_list_temp;
                if(trav_list == NULL)
                {
                    break;
                }            
            }            
        }        
#ifdef __unix__ //{
        pthread_mutex_unlock(&sw_timer_ll_mutex);
        usleep(500000); // sleep for 500 msec     
#endif //}        
    }    
   return NULL;
}


static void delete_timer_node(sw_timer *trav_list)
{
    if( trav_list == sw_timer_ll_head)
    {
        sw_timer_ll_head = trav_list->next;        
        trav_list->state = TIMER_STATE_STOPPED;        
#ifdef __unix__ //{
        //free(trav_list);
#endif //}
    }
    else
    {
        sw_timer *temp_timer_trav = sw_timer_ll_head;
        while(temp_timer_trav->next != trav_list)
        {
            temp_timer_trav = temp_timer_trav->next;
        }
        if(temp_timer_trav->next == trav_list )
        {
            trav_list->state = TIMER_STATE_STOPPED;
            temp_timer_trav->next = trav_list->next;
        }
#ifdef __unix__ //{
        //free(trav_list);
#endif //}
    }    
}


int sw_timer_init(void)
{
    // intialise timer link list.
    sw_timer_ll_head = NULL;
  
#ifdef __unix__ //{
    // initialise mutex.
    //sw_timer_ll_mutex = PTHREAD_MUTEX_INITIALIZER ;
    pthread_mutex_init ( &sw_timer_ll_mutex, NULL);
    
    if(sw_timer_thread_start() == 0)
    {
        // set timer init flag
        sw_timer_init_flag = 1;
    }
#else //}{

    // init ISRs
    // register sw_timer_thread_proc with ISR
    sw_timer_init_flag = 1;    
#endif //}
    
    //printf("timer init success !! \n");
    return 0;    
}

#ifdef __unix__  //{
static int sw_timer_thread_start(void)
{
    int retval;
    
    if((0 == sw_timer_init_flag) && (0 == sw_timer_run_flag)) 
    {
        // start the timer thread.    
        retval = pthread_create(&timer_thread,NULL,sw_timer_thread_proc,NULL);
        
        assert(retval == 0);
        
        // set run flag to true.
        sw_timer_run_flag = 1;
        
        //printf("timer thread created !! \n");
    }    
    return 0;
}
#endif //}


int sw_timer_stop(sw_timer_handle timer_hnd)
{
    sw_timer *trav_list = (sw_timer *) timer_hnd;

     if(trav_list->state == TIMER_STATE_STOPPED)
     {
         return 0;
     }
     
    delete_timer_node(trav_list);       // this will remove timer object from timer_object_queue_list
    return 0;
    
//     if( trav_list == sw_timer_ll_head)
//     {
//         trav_list->state = TIMER_STATE_STOPPED;
//     }
//     else
//     {
//         sw_timer *temp_timer_trav = sw_timer_ll_head;
//         while(temp_timer_trav->next != NULL )
//         {
//             if(temp_timer_trav->next == trav_list)
//             {
//                 trav_list->state = TIMER_STATE_STOPPED;
//                 return 0;
//             }
//         }
//     }        
//     return -1;
}


sw_timer_handle sw_timer_create(int timeout_ms, cb_func_ptr cb_func_ptr_on_time_out, sw_timer *timer_node, void* data)
{
    long int milli_seconds;
    struct timeb the_time;
    
    if(timer_node == NULL)
    {
        return NULL;           
    }
    
    if(timeout_ms <= 0)
    {
        return NULL;
    }
    
    if(cb_func_ptr_on_time_out == NULL)
    {
        return NULL;
    }
    
    //printf("in sw_timer_create !! \n");
    
    //get the start time of timer node
    ftime (&the_time);
    milli_seconds = (the_time.time * 1000) + the_time.millitm;


    //fill the sw_timer structure
    timer_node->time_out    = timeout_ms;
    timer_node->start_time  = (milli_seconds);
    timer_node->cb_func_ptr_on_time_out = cb_func_ptr_on_time_out;
    timer_node->data        = data;
    timer_node->next        = NULL; 
    timer_node->state       = TIMER_STATE_IDLE;
    
    //check whether the list is empty or not
    if(sw_timer_ll_head == NULL)
    {
        sw_timer_ll_head = timer_node;
    }
    else        // add the timer node at the end of list
    {
        sw_timer *trav_list = sw_timer_ll_head;        
        
        while(trav_list->next != NULL)
        {
            trav_list=trav_list->next;
        }
        
        trav_list->next = timer_node;      
    }  
    
    //printf("timer node created !! \n");
    return timer_node;      
}

int sw_timer_start(sw_timer_handle timer_hnd)
{
    sw_timer *timer = (sw_timer *) timer_hnd;
    
    if(timer == NULL)
    {
        return -1; /*Invalid Args*/
    }
    
    timer->state = TIMER_STATE_RUNNING;
    
    return 0;
}


int sw_timer_term(void)
{
    sw_timer_run_flag  = 0;

#ifdef __unix__  //{    
    //printf("\n\ntimer_thread_terminated\n\n");
    pthread_join(timer_thread, NULL);
#endif //}   

    return 0;
}

/*
timer_thread()
{
    current_time = 0
    while(1)
    {
        check the queue and if timeout occured then call callback function
        if(current_time > start_time +  timeout) then call callback
        
        usleep(250000); // sleep for 250 msec
        current_time = current_time + 250 msec
    }
}
*/