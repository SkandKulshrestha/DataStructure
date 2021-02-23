

#include <stdio.h>          // printf

#include "stack.h"

#ifndef LOG_ERROR_MSG
    #define LOG_ERROR_MSG(fmt) printf("[%s:%d] " fmt, __FUNCTION__, __LINE__)
#endif

#ifndef LOG_ERROR_MSG_ARGS
    #define LOG_ERROR_MSG_ARGS(fmt, ...) printf("[%s:%d] " fmt, __FUNCTION__, __LINE__, __VA_ARGS__)
#endif

// see header file for description
void vStackInit(STACK *ptStack, uint32_t u32Size)
{
    // allocate the memory
    ptStack->ptData = (STACK_ELEMENT *)malloc(u32Size * sizeof(STACK_ELEMENT));

    // set the size
    ptStack->u32StackSize = u32Size;

    // set the top
    ptStack->u32Top = 0;
}

// see header file for description
void vStackPush(STACK *ptStack, STACK_ELEMENT tData)
{
    // check the space available
    if (bStackIsFull(ptStack))
    {
        // stack is full
        LOG_ERROR_MSG("Stack Overflow\n");
    }
    else
    {
        // increment the top and push the data
        ptStack->ptData[ptStack->u32Top++] = tData;
    }
}

// see header file for description
STACK_ELEMENT tStackPop(STACK *ptStack)
{
    STACK_ELEMENT tData = 0;

    if (bStackIsEmpty(ptStack))
    {
        // stack is empty
        LOG_ERROR_MSG("Stack Underflow\n");
    }
    else
    {
        // pop out the data and decrement the top
        tData = ptStack->ptData[--ptStack->u32Top];
    }

    return tData;
}

// see header file for description
bool bStackIsEmpty(STACK *ptStack)
{
    return (ptStack->u32Top == 0);
}

// see header file for description
bool bStackIsFull(STACK *ptStack)
{
    return (ptStack->u32Top == ptStack->u32StackSize);
}

// see header file for description
STACK_ELEMENT tStackPeek(STACK *ptStack)
{
    STACK_ELEMENT tData = 0;

    if (bStackIsEmpty(ptStack))
    {
        // stack is empty
        LOG_ERROR_MSG("Stack Underflow\n");
    }
    else
    {
        // get the data pointed by top
        tData = ptStack->ptData[ptStack->u32Top - 1];
    }

    return tData;
}

// see header file for description
void vStackExit(STACK *ptStack)
{
    // release the memory
    free(ptStack->ptData);

    // reset the size
    ptStack->u32StackSize = 0;

    // reset the top
    ptStack->u32Top = 0;
}
