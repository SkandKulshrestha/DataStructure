#ifndef _STACK_H_
#define _STACK_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack_s
{
    int32_t     i32MaxSize;
    int32_t     i32Top;
    int32_t     *pi32Items;
} stack;

void vStackInitialize(stack *ptStack, int32_t i32Size);
void vStackPush(stack *ptStack, int32_t i32Item);
int32_t i32StackPop(stack *ptStack);
bool bStackIsEmpty(stack *ptStack);
bool bStackIsFull(stack *ptStack);
int32_t i32StackPeek(stack *ptStack);

#endif //_STACK_H_
