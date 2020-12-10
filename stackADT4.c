#include <stdio.h>
#include <stdlib.h>
#ifdef IMP
#include "reference_stackADT.h"
#else
#include "stackADT.h"
#endif
#include "memtrace.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* Stack structure */
struct Stack {
    int top;
    unsigned int capacity;    int *items;
};

struct Stack *Stack_create(unsigned int capacity){
    struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->items = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

bool Stack_is_empty(struct Stack* stack)
{
    return stack->top == -1;
}

bool Stack_is_full(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}