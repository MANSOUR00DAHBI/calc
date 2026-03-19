// main.c
//  calculator.c
#include "eval.h"

int main()
{
    char expr[256];
 
    
    printf("Enter the mathematical expression: ");
    if (!fgets(expr, sizeof(expr), stdin))
    {
        printf("Input error\n");
        return 1;
    }
    token tokens[100];
    double n = tokenize(expr, tokens, 100);
    if (n < 0)
    {
        printf("Failed to parse the expression\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (tokens[i].type == TOK_OPERAND)
        {
            printf("number: %lld\n", (long long)tokens[i].value);
        }
        else
        {
            printf("operation: '%c'\n", (char)tokens[i].type);
        }
    }
    Word result = evaluate(tokens, n);
    printf("Output : %lld\n", (long long)result);
    return 0;
}
