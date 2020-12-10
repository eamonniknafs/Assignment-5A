#include <stdio.h>
#include <stdlib.h>
#ifdef IMP
#include "reference_stackADT.h"
#else
#include "stackADT.h"
#endif
#include "memtrace.h"

#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

#define SIZE 50

struct stack_type {
  void * items[SIZE];
  int top;
};

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

Stack Stack_create(void)
{
  Stack stack = malloc(sizeof(struct stack_type));
  if (stack == NULL)
    terminate("Error in create: stack could not be created.");
  stack->top = 0;
  return stack;
}

bool Stack_is_empty(Stack stack)
{
  return stack->top == 0;
}

bool Stack_is_full(Stack stack)
{
  return stack->top == SIZE;
}

void Stack_push(Stack stack, void * i)
{
  if (Stack_is_full(stack))
    terminate("Error in push: stack is full.");
  stack->items[stack->top++] = i;
}

void * Stack_pop(Stack stack)
{
  if (Stack_is_empty(stack))
    terminate("Error in pop: stack is empty.");
  return stack->items[--stack->top];
}

