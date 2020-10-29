

#include <stdio.h>          // printf
#include <string.h>

#include "stack.h"

#ifndef LOG_ERROR_MSG
    #define LOG_ERROR_MSG(fmt) printf("[%s:%d] " fmt, __FUNCTION__, __LINE__)
#endif

#ifndef LOG_ERROR_MSG_ARGS
    #define LOG_ERROR_MSG_ARGS(fmt, ...) printf("[%s:%d] " fmt, __FUNCTION__, __LINE__, __VA_ARGS__)
#endif

// see header file for description
void vStackInit(STACK *ptStack, uint32_t u32Size, uint32_t u32ElementSize)
{
    // allocate the memory
    ptStack->pvData = malloc(u32Size * u32ElementSize);

    // set the size
    ptStack->u32StackSize = u32Size;

    // set the top
    ptStack->u32Top = 0;
}

// see header file for description
void vStackPush(STACK *ptStack, void *pvData)
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
        memcpy((u8*)(ptStack->pvData) + ptStack->u32Top, pvData, ptStack->u32ElementSize);
        ptStack->u32Top++;
    }
}

// see header file for description
void vStackPop(STACK *ptStack, void *pvData)
{
    if (bStackIsEmpty(ptStack))
    {
        // stack is empty
        LOG_ERROR_MSG("Stack Underflow\n");
    }
    else
    {
        // pop out the data and decrement the top
        --ptStack->u32Top;
        memcpy(pvData, (u8*)(ptStack->pvData) + ptStack->u32Top, ptStack->u32ElementSize);
    }
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
void vStackPeek(STACK *ptStack, void *pvData)
{
    if (bStackIsEmpty(ptStack))
    {
        // stack is empty
        LOG_ERROR_MSG("Stack Underflow\n");
    }
    else
    {
        // get the data pointed by top
        memcpy(pvData, (u8*)(ptStack->pvData) + ptStack->u32Top - 1, ptStack->u32ElementSize);
    }
}

// see header file for description
void vStackExit(STACK *ptStack)
{
    // release the memory
    free(ptStack->pvData);

    // reset the size
    ptStack->u32StackSize = 0;

    // reset the element size
    ptStack->u32ElementSize = 0;

    // reset the top
    ptStack->u32Top = 0;
}
