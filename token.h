//toke.h
#ifndef H_TOKEN
#define H_TOKEN
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
    OB_BAD = 15
}type_token;

typedef enum{
    ERR_OK = 0,
    ERR_STACK_OVERFLOW,
    ERR_STACK_UNDERFLOW,
    ERR_DIVIDEBY_ZERO
}Error_token;

typedef struct toke{
    Word value;
    Word type ;
}toke;

#endif
