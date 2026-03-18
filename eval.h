#ifndef EVAL_H
#define EVAL_H
#include "token.h"
#include "stock.h"
int tokenize(char *expr, token tokens[], int max_tokens);
int precedence(type_token op);
Word apply_op(Word a, Word b, type_token op);
Word evaluate(token tokens[], int n);
#endif