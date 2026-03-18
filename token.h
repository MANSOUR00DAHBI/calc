//toke.h
#ifndef H_TOKEN
#define H_TOKEN
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

typedef int64_t Word ;
typedef enum {
    TOK_OPERAND = 0,
    TOK_OPRATOP = 1,
    OP_PLUS = '+',
    OP_MINUS = '-',
    OP_MULTIPLY = '*',
    OP_DIVIDE = '/',
    OP_POWER = '^',
    OP_MOD = '%',
    OP_RPAREN = ')',
    OP_LPAREN = '(',
    OP_BAD = 11
}type_token;

typedef enum{
    ERR_OK = 0,
    ERR_STACK_OVERFLOW,
    ERR_STACK_UNDERFLOW,
    ERR_DIVIDEBY_ZERO
}Error_token;

typedef struct token{
    Word value;
    Word type ;
}token;

typedef struct operation{
    char symbol;
    Word value ;
    int  precedence_in_stack ;
    int  precedence_out_stack;
}operation;

extern operation oplist[];
char *GetNextToken( char *input_char, token *tkn);

#endif
