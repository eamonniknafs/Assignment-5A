/*
 * stackADT4.c: a simple implementation of a stack of size 50.
 *
 * Name: Eamon Niknafs
 * email: en@bu.edu
 *
 * NOTE: The texbook resources (found here: http://knking.com/books/c2/programs/stackADT.c)
 * were used as a reference to write this program.
 */

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

#define SIZE 50 //Size of stack

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

void Stack_destroy(Stack stack)
{
    for (int i = 0; i < stack->top; i++)
    {
        free(stack->items[i]);
    }
    free (stack);
}

void Stack_make_empty(Stack stack)
{
    while (!Stack_is_empty(stack)) Stack_pop(stack);
    stack->top = 0;
}