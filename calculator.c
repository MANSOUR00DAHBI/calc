//main.c 
// calculator.c
#include "eval.h"

int main() {
    char expr[256];
    printf("Enter the mathematical expression: \n");
    if (!fgets(expr, sizeof(expr), stdin)) {
        printf("Input error\n");
        return 1;
    }

    token tokens[100];
    int n = tokenize(expr, tokens, 100);
    if (n < 0) {
        printf("Failed to parse the expression\n");
        return 1;
    }

    Word result = evaluate(tokens, n);
    printf("Output : %lld\n", (long long)result);

    return 0;
}

