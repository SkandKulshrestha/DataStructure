#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdint.h>         // int32_t
#include <stdio.h>          // printf
#include <stdlib.h>         // malloc, free
#include <stdbool.h>        // bool, true, false

/**
 *  Structure to hold the queue
 */
typedef struct queue_s
{
    /// Maximum number of elements queue can hold
    int32_t         i32QueueSize;

    /// Front of the queue
    int32_t         i32Front;

    /// Rear of the queue
    int32_t         i32Rear;

    /// Pointer to the array that holds elements
    QUEUE_ELEMENT  *ptData;
} QUEUE;

/**
 *  Initialize the queue.
 *
 *  @param ptQueue      pointer to the queue
 *  @param i32Size      size of queue to be allocated
 */
void vQueueInit(QUEUE *ptQueue, int32_t i32Size);

/**
 *  Push the data into the queue.
 *
 *  @param ptQueue      pointer to the queue
 *  @param i32Data      data to be pushed
 */
void vQueueEnqueue(QUEUE *ptQueue, QUEUE_ELEMENT tData);

/**
 *  Pop the data out from the queue.
 *
 *  @param ptQueue      pointer to the queue
 *
 *  @return data extracted from rear of queue
 */
QUEUE_ELEMENT tQueueDequeue(QUEUE *ptQueue);

/**
 *  Check whether queue is empty or not.
 *
 *  @param ptQueue      pointer to the queue
 *
 *  @return true, if queue is empty
 *          false, otherwise
 */
bool bQueueIsEmpty(QUEUE *ptQueue);

/**
 *  Check whether queue is full or not.
 *
 *  @param ptQueue      pointer to the queue
 *
 *  @return true, if queue is full
 *          false, otherwise
 */
bool bQueueIsFull(QUEUE *ptQueue);

/**
 *  De-initialize the queue.
 *
 *  @param ptQueue      pointer to the queue
 */
void vQueueExit(QUEUE *ptQueue);

#endif // _QUEUE_H_
