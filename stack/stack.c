#include "stack.h"

// see header file for description
void vStackInit(stack *ptStack, int32_t i32Size)
{
    // allocate the memory
    ptStack->pi32Data = (int32_t *)malloc(i32Size * sizeof(int32_t));
    // set the size
    ptStack->i32MaxSize = i32Size;
    // set the top
    ptStack->i32Top = 0;
}

// see header file for description
void vStackPush(stack *ptStack, int32_t i32Data)
{
    // check the space available
    if (ptStack->i32Top == ptStack->i32MaxSize)
    {
        // stack is full
        printf("Stack Overflow\n");
    }
    else
    {
        // push the data and increment the top
        ptStack->pi32Data[ptStack->i32Top++] = i32Data;
    }
}

// see header file for description
int32_t i32StackPop(stack *ptStack)
{
    int32_t i32Data = 0;
    if (ptStack->i32Top == 0)
    {
        // stack is empty
        printf("Stack Underflow\n");
    }
    else
    {
        // pop out the data and decrement the top
        i32Data = ptStack->pi32Data[--ptStack->i32Top];
    }
    return i32Data;
}

// see header file for description
bool bStackIsEmpty(stack *ptStack)
{
    return (ptStack->i32Top == 0);
}

// see header file for description
bool bStackIsFull(stack *ptStack)
{
    return (ptStack->i32Top == ptStack->i32MaxSize);
}

// see header file for description
int32_t i32StackPeek(stack *ptStack)
{
    int32_t i32Data = 0;
    if (ptStack->i32Top == 0)
    {
        // stack is empty
        printf("Stack Underflow\n");
    }
    else
    {
        // extract the data from the stack
        i32Data = ptStack->pi32Data[ptStack->i32Top - 1];
    }
    return i32Data;
}

// see header file for description
void vStackExit(stack *ptStack)
{
    // release the memory
    free(ptStack->pi32Data);
    // reset the size
    ptStack->i32MaxSize = 0;
    // reset the top
    ptStack->i32Top = 0;
}
