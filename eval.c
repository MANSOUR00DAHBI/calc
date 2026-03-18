// eval.c
#include "eval.h"

// Function to determine process priority
int precedence(type_token op)
{
    switch (op)
    {
    case OP_PLUS:
    case OP_MINUS:
        return 1;
    case OP_MULTIPLY:
    case OP_DIVIDE:
    case OP_MOD:
        return 2;
    case OP_POWER:
        return 3;
    default:
        return 0;
    }
}
// Execute a single operation between two numbers
Word apply_op(Word a, Word b, type_token op)
{
    switch (op)
    {
    case OP_PLUS:
        return a + b;
    case OP_MINUS:
        return a - b;
    case OP_MULTIPLY:
        return a * b;
    case OP_DIVIDE:
        return b != 0 ? a / b : 0; // Handling division by zero
    case OP_MOD:
        return a % b;
    case OP_POWER:
        return (Word)pow(a, b);
    default:
        return 0;
    }
}

// Evaluate a complete expression using the stack
Word evaluate(token tokens[], int n)
{
    Stack *values = create_Stack(50);
    Stack *ops = create_Stack(50);

    for (int i = 0; i < n; i++)
    {
        if (tokens[i].type == TOK_OPERAND)
        {
            push(values, tokens[i].value);
        }
        else if (tokens[i].type == OP_LPAREN)
        {
            push(ops, tokens[i].type);
        }
        else if (tokens[i].type == OP_RPAREN)
        {
            while (!is_empty(ops) && peek(ops) != OP_LPAREN)
            {
                Word val2 = pop(values);
                Word val1 = pop(values);
                type_token op = pop(ops);
                push(values, apply_op(val1, val2, op));
            }
            pop(ops);
        }
        else
        {
            while (!is_empty(ops) && precedence(peek(ops)) >= precedence(tokens[i].type))
            {
                Word val2 = pop(values);
                Word val1 = pop(values);
                type_token op = pop(ops);
                push(values, apply_op(val1, val2, op));
            }
            push(ops, tokens[i].type);
        }
    }
    
    while (!is_empty(ops))
    {
        Word val2 = pop(values);
        Word val1 = pop(values);
        type_token op = pop(ops);
        push(values, apply_op(val1, val2, op));
    }

    if (is_empty(values))
    {
        fprintf(stderr, "Error: no result\n");
        return 0;
    }
    return pop(values);
}
