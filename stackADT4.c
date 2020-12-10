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
  int items[SIZE];
  int top;
};

Stack Stack_create(void)
{
  Stack stack = malloc(sizeof(struct stack_type));
  if (stack == NULL)
    exit(1);
  stack->top = 0;
  return s;
}