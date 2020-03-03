#include "stack.h"

/**
 *
 */
void vStackInitialize(stack *ptStack, int32_t i32Size)
{
    ptStack->pi32Items = (int32_t *)malloc(i32Size * sizeof(int32_t));
    ptStack->i32MaxSize = i32Size;
    ptStack->i32Top = 0;
}

/**
 *
 */
void vStackPush(stack *ptStack, int32_t i32Item)
{
    if (ptStack->i32Top == ptStack->i32MaxSize)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptStack->pi32Items[ptStack->i32Top++] = i32Item;
    }
}

/**
 *
 */
int32_t i32StackPop(stack *ptStack)
{
    int32_t i32Item = 0;
    if (ptStack->i32Top == 0)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        i32Item = ptStack->pi32Items[--ptStack->i32Top];
    }
    return i32Item; 
}

/**
 *
 */
bool bStackIsEmpty(stack *ptStack)
{
    return (ptStack->i32Top == 0);
}

/**
 *
 */
bool bStackIsFull(stack *ptStack)
{
    return (ptStack->i32Top == ptStack->i32MaxSize);
}

/**
 *
 */
int32_t i32StackPeek(stack *ptStack)
{
    int32_t i32Item = 0;
    if (ptStack->i32Top == 0)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        i32Item = ptStack->pi32Items[ptStack->i32Top - 1];
    }
    return i32Item;
}
