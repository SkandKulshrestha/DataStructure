#ifndef _STACK_H_
#define _STACK_H_

#include <stdint.h>         // int32_t
#include <stdlib.h>         // malloc, free
#include <stdbool.h>        // bool, true, false

#include "config.h"

/**
 *  Structure to hold the stack
 */
typedef struct stack_s
{
    /// Maximum number of elements stack can hold
    uint32_t        u32StackSize;

    /// Top of the stack
    uint32_t        u32Top;

    /// Pointer to the array that holds elements
    STACK_ELEMENT  *ptData;
} STACK;

/**
 *  Initialize the stack.
 *
 *  @param ptStack      pointer to the stack
 *  @param u32Size      size of stack to be allocated
 */
void vStackInit(STACK *ptStack, uint32_t u32Size);

/**
 *  Push the data onto the stack.
 *
 *  @param ptStack      pointer to the stack
 *  @param tData        data to be pushed
 */
void vStackPush(STACK *ptStack, STACK_ELEMENT tData);

/**
 *  Pop the data out from the stack.
 *
 *  @param ptStack      pointer to the stack
 *
 *  @return data popped from top of stack
 */
STACK_ELEMENT tStackPop(STACK *ptStack);

/**
 *  Check whether stack is empty or not.
 *
 *  @param ptStack      pointer to the stack
 *
 *  @return true, if stack is empty
 *          false, otherwise
 */
bool bStackIsEmpty(STACK *ptStack);

/**
 *  Check whether stack is full or not.
 *
 *  @param ptStack      pointer to the stack
 *
 *  @return true, if stack is full
 *          false, otherwise
 */
bool bStackIsFull(STACK *ptStack);

/**
 *  Data on top of the stack without popping it.
 *
 *  @param ptStack      pointer to the stack
 *
 *  @return data on the top of stack
 */
STACK_ELEMENT tStackPeek(STACK *ptStack);

/**
 *  De-initialize the stack.
 *
 *  @param ptStack      pointer to the stack
 */
void vStackExit(STACK *ptStack);

#endif //_STACK_H_
