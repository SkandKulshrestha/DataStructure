#include "queue.h"

#ifndef LOG_ERROR_MSG
    #define LOG_ERROR_MSG(fmt) printf("[%s:%d] " fmt, __FUNCTION__, __LINE__)
#endif

#ifndef LOG_ERROR_MSG_ARGS
    #define LOG_ERROR_MSG_ARGS(fmt, ...) printf("[%s:%d] " fmt, __FUNCTION__, __LINE__, __VA_ARGS__)
#endif

// see header file for description
void vQueueInit(QUEUE *ptQueue, int32_t i32Size)
{
    // allocate the memory
    ptQueue->ptData = (QUEUE_ELEMENT *)malloc(i32Size * sizeof(QUEUE_ELEMENT));

    // set the size
    ptQueue->i32QueueSize = i32Size;

    // set the front
    ptQueue->i32Front = -1;

    // set the rear
    ptQueue->i32Rear = -1;
}

// see header file for description
void vQueueEnqueue(QUEUE *ptQueue, QUEUE_ELEMENT tData)
{
    int32_t i32Rear = ptQueue->i32Rear;

    // increment the rear
    ptQueue->i32Rear = (ptQueue->i32Rear + 1) % ptQueue->i32QueueSize;

    // check the space available
    if (ptQueue->i32Rear == ptQueue->i32Front)
    {
        // queue is full
        LOG_ERROR_MSG("Queue Overflow\n");

        // reset the rear
        ptQueue->i32Rear = i32Rear;
    }
    else
    {
        // put data on the queue
        ptQueue->ptData[ptQueue->i32Rear] = tData;
        
        // check and set the front
        if (ptQueue->i32Front == -1)
        {
            ptQueue->i32Front = 0;
        }
    }
}

// see header file for description
QUEUE_ELEMENT tQueueDequeue(QUEUE *ptQueue)
{
    QUEUE_ELEMENT tData = 0;

    if (bQueueIsEmpty(ptQueue))
    {
        // queue is empty
        LOG_ERROR_MSG("Queue Underflow\n");
    }
    else
    {
        // extract the data from the queue
        tData = ptQueue->ptData[ptQueue->i32Front];

        // set the front
        if (ptQueue->i32Front == ptQueue->i32Rear)
        {
            ptQueue->i32Front = ptQueue->i32Rear = -1;
        }
        else
        {
            ptQueue->i32Front = (ptQueue->i32Front + 1) % ptQueue->i32QueueSize;
        }
    }
    return tData;
}

// see header file for description
bool bQueueIsEmpty(QUEUE *ptQueue)
{
    return (ptQueue->i32Rear == -1);
}

// see header file for description
bool bQueueIsFull(QUEUE *ptQueue)
{
    return (ptQueue->i32Front == (ptQueue->i32Rear + 1) % ptQueue->i32QueueSize);
}

// see header file for description
void vQueueExit(QUEUE *ptQueue)
{
    // release the memory
    free(ptQueue->ptData);

    // reset the size
    ptQueue->i32QueueSize = 0;

    // reset the front
    ptQueue->i32Front = -1;

    // reset the rear
    ptQueue->i32Rear = -1;
}
