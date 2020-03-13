#include "queue.h"

// see header file for description
void vQueueInitialize(queue *ptQueue, int32_t i32Size)
{
    // allocate the memory
    ptQueue->pi32Data = (int32_t *)malloc(i32Size * sizeof(int32_t));
    // set the size
    ptQueue->i32MaxSize = i32Size;
    // set the front
    ptQueue->i32Front = -1;
    // set the rear
    ptQueue->i32Rear = -1;
}

// see header file for description
void vQueueEnqueue(queue *ptQueue, int32_t i32Data)
{
    int32_t i32Rear = ptQueue->i32Rear;
    // increment the rear
    ptQueue->i32Rear = (ptQueue->i32Rear + 1) % ptQueue->i32MaxSize;

    // check the space available
    if (ptQueue->i32Rear == ptQueue->i32Front)
    {
        // queue is full
        printf("Queue Overflow\n");
        // reset the rear
        ptQueue->i32Rear = i32Rear;
    }
    else
    {
        // put data on the queue
        ptQueue->pi32Data[ptQueue->i32Rear] = i32Data;
        
        // check and set the front
        if (ptQueue->i32Front == -1)
        {
            ptQueue->i32Front = 0;
        }
    }
}

// see header file for description
int32_t i32QueueDequeue(queue *ptQueue)
{
    int32_t i32Data = 0;

    if (ptQueue->i32Rear == -1)
    {
        // queue is empty
        printf("Queue Underflow\n");
    }
    else
    {
        // extract the data from the queue
        i32Data = ptQueue->pi32Data[ptQueue->i32Front];

        // set the front
        if (ptQueue->i32Front == ptQueue->i32Rear)
        {
            ptQueue->i32Front = ptQueue->i32Rear = -1;
        }
        else
        {
            ptQueue->i32Front = (ptQueue->i32Front + 1) % ptQueue->i32MaxSize;
        }
    }
    return i32Data;
}

// see header file for description
bool bQueueIsEmpty(queue *ptQueue)
{
    return (ptQueue->i32Rear == -1);
}

// see header file for description
bool bQueueIsFull(queue *ptQueue)
{
    return (ptQueue->i32Front == (ptQueue->i32Rear + 1) % ptQueue->i32MaxSize);
}

// see header file for description
void vQueueExit(queue *ptQueue)
{
    // release the memory
    free(ptQueue->pi32Data);
    // reset the size
    ptQueue->i32MaxSize = 0;
    // reset the front
    ptQueue->i32Front = -1;
    // reset the rear
    ptQueue->i32Rear = -1;
}
