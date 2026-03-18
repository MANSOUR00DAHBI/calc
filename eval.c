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
Word evaluate(token tokens[], int n) {
    Stack *values = create_Stack(20);
    Stack *ops = create_Stack(20);

    for (int i = 0; i < n; i++) {
        if (tokens[i].type == TOK_OPERAND) {
            push(values, tokens[i].value);
        } else if (tokens[i].type == OP_LPAREN) {
            push(ops, tokens[i].type);
        } else if (tokens[i].type == OP_RPAREN) {
            while (!is_empty(ops) && peek(ops) != OP_LPAREN) {
                if (is_empty(values)) {
                    fprintf(stderr, "Error: missing operand\n");
                    return 0;
                }
                Word val2 = pop(values);
                if (is_empty(values)) {
                    fprintf(stderr, "Error: missing operand\n");
                    return 0;
                }
                Word val1 = pop(values);
                type_token op = pop(ops);
                push(values, apply_op(val1, val2, op));
            }
            if (!is_empty(ops)) pop(ops);
        } else {
            while (!is_empty(ops) && precedence(peek(ops)) >= precedence(tokens[i].type)) {
                if (is_empty(values)) {
                    fprintf(stderr, "Error: missing operand\n");
                    return 0;
                }
                Word val2 = pop(values);
                if (is_empty(values)) {
                    fprintf(stderr, "Error: missing operand\n");
                    return 0;
                }
                Word val1 = pop(values);
                type_token op = pop(ops);
                push(values, apply_op(val1, val2, op));
            }
            push(ops, tokens[i].type);
        }
    }

    while (!is_empty(ops)) {
        if (is_empty(values)) {
            fprintf(stderr, "Error: missing operand\n");
            return 0;
        }
        Word val2 = pop(values);
        if (is_empty(values)) {
            fprintf(stderr, "Error: missing operand\n");
            return 0;
        }
        Word val1 = pop(values);
        type_token op = pop(ops);
          Word res = apply_op(val1, val2, op);
        push(values, res);
    }
if (is_empty(values)) {
    fprintf(stderr, "Error: no result (values stack empty)\n");
    return 0;
}
Word result = pop(values);
// If other elements remain in the stack, this indicates a parsing error.
if (!is_empty(values)) {
    fprintf(stderr, "Error: extra operands remain\n");
    return 0;
}
return result;

}
