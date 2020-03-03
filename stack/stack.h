#ifndef _STACK_H_
#define _STACK_H_

#include <stdint.h>         // int32_t
#include <stdio.h>          // printf
#include <stdlib.h>         // malloc, free
#include <stdbool.h>        // bool, true, false

/**
 *  Structure to hold the stack
 */
typedef struct stack_s
{
    /// Maximum number of elements stack can hold
    int32_t     i32MaxSize;
    /// Top of the stack
    int32_t     i32Top;
    /// Pointer to the array that holds elements
    int32_t     *pi32Data;
} stack;

/**
 *  Initialize the stack.
 *
 *  @param ptStack      pointer to the stack
 *  @param i32Size      size of stack to be allocated
 */
void vStackInit(stack *ptStack, int32_t i32Size);

/**
 *  Push the data onto the stack.
 *
 *  @param ptStack      pointer to the stack
 *  @param i32Data      data to be pushed
 */
void vStackPush(stack *ptStack, int32_t i32Data);

/**
 *  Pop the data out from the stack.
 *
 *  @param ptStack      pointer to the stack
 *
 *  @return data popped from top of stack
 */
int32_t i32StackPop(stack *ptStack);

/**
 *  Check whether stack is empty or not.
 *
 *  @param ptStack      pointer to the stack
 *
 *  @return true, if stack is empty
 *          false, otherwise
 */
bool bStackIsEmpty(stack *ptStack);

/**
 *  Check whether stack is full or not.
 *
 *  @param ptStack      pointer to the stack
 *
 *  @return true, if stack is full
 *          false, otherwise
 */
bool bStackIsFull(stack *ptStack);

/**
 *  Data on top of the stack without popping it.
 *
 *  @param ptStack      pointer to the stack
 *
 *  @return data on the top of stack
 */
int32_t i32StackPeek(stack *ptStack);

/**
 *  De-initialize the stack.
 *
 *  @param ptStack      pointer to the stack
 */
void vStackExit(stack *ptStack);

#endif //_STACK_H_
