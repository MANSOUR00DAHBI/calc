#include "token.h"

struct operation oplist[] = {
    { '+', OP_PLUS,     2, 1 },
    { '-', OP_MINUS,    2, 1 },
    { '*', OP_MULTIPLY, 4, 3 },
    { '/', OP_DIVIDE,   4, 3 },
    { '%', OP_MOD,      4, 3 },
    { '^', OP_POWER,    6, 5 },
    { '(', OP_LPAREN,   0, 7 },
    { ')', OP_RPAREN,   7, 0 }
};


char * GetNextToken ( char *input_char , token *tkn){
    while(*input_char  && isspace(*input_char)) input_char++; // Skip leading withspace
    if(*input_char == '\0'){
        tkn->type = OP_BAD;
        tkn->value = 0 ;
        return input_char;
    }
    if(isdigit(*input_char)){
        Word val = 0;
        while(*input_char && isdigit(*input_char)){
            val = val * 10 + (*input_char - '0');
            input_char++;
        }
        tkn->type = TOK_OPERAND;
        tkn->value = val;
        return input_char;
    }
    switch(*input_char){
        case '+' : tkn->type = OP_PLUS ; break;
        case '-' : tkn->type = OP_MINUS ; break;
        case '*' : tkn->type = OP_MULTIPLY  ; break;
        case '/' : tkn->type = OP_DIVIDE ; break;
        case '^' : tkn->type = OP_POWER ; break;
        case '%' : tkn->type = OP_MOD ; break;
        case '(' : tkn->type =  OP_LPAREN ; break;
        case ')' : tkn->type = OP_RPAREN  ; break;
        default : tkn->type = OP_BAD;
    }
    tkn->value = *input_char;
    input_char++;
    return input_char;

}
int tokenize(char *expr, token tokens[], int max_tokens) {
    int count = 0;
    char *p = expr;

    while (*p != '\0' && count < max_tokens) {
        token t;
        p = GetNextToken(p, &t);

        if (t.type == OP_BAD) {
            printf("Error: invlide code '%c'\n", *p);
            return -1;
        }

        tokens[count++] = t;
    }

    return count; // count number useing
}
#define TEST_STOCK
#ifdef TEST_STOCK
int main() {
    char expr[] = "12+3*4";
    token tokens[20];
    int n = tokenize(expr, tokens, 20);

    for (int i = 0; i < n; i++) {
        if (tokens[i].type == TOK_OPERAND) {
            printf("number: %lld\n", (long long)tokens[i].value);
        } else {
            printf("operation: '%c'\n", (char)tokens[i].type);
        }
    }
    return 0;
}
#endif