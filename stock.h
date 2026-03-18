#ifndef STOCK_H
#define STOCK_H
#include "token.h"

typedef int64_t Item;

typedef struct Stack{
    Item *contents;
    Item top;
    Item size;
}Stack;

Stack *create_Stack(Item initial_size);
void make_empty(Stack *s);
bool is_empty(Stack *s);
bool is_full(Stack *s);
void push(Stack *s,Item i);
Item pop(Stack *s);
Item peek(Stack *s);
static void stack_underflow(void);
static void reallocate(Stack *stack);

#endif