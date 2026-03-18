#ifndef EVAL_H
#define EVAL_H
#include "stock.h"
int precedence(type_token op);
Word apply_op(Word a, Word b, type_token op);
Word evaluate(token tokens[], int n);
#endif