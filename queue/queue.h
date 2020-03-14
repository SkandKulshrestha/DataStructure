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
    int32_t     i32MaxSize;
    /// Front of the queue
    int32_t     i32Front;
    /// Rear of the queue
    int32_t     i32Rear;
    /// Pointer to the array that holds elements
    int32_t     *pi32Data;
} queue;

/**
 *  Initialize the queue.
 *
 *  @param ptQueue      pointer to the queue
 *  @param i32Size      size of queue to be allocated
 */
void vQueueInit(queue *ptQueue, int32_t i32Size);

/**
 *  Push the data into the queue.
 *
 *  @param ptQueue      pointer to the queue
 *  @param i32Data      data to be pushed
 */
void vQueueEnqueue(queue *ptQueue, int32_t i32Data);

/**
 *  Pop the data out from the queue.
 *
 *  @param ptQueue      pointer to the queue
 *
 *  @return data extracted from rear of queue
 */
int32_t i32QueueDequeue(queue *ptQueue);

/**
 *  Check whether queue is empty or not.
 *
 *  @param ptQueue      pointer to the queue
 *
 *  @return true, if queue is empty
 *          false, otherwise
 */
bool bQueueIsEmpty(queue *ptQueue);

/**
 *  Check whether queue is full or not.
 *
 *  @param ptQueue      pointer to the queue
 *
 *  @return true, if queue is full
 *          false, otherwise
 */
bool bQueueIsFull(queue *ptQueue);

/**
 *  De-initialize the queue.
 *
 *  @param ptQueue      pointer to the queue
 */
void vQueueExit(queue *ptQueue);

#endif // _QUEUE_H_
