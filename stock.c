 #include "stock.h"

 Stack *create_stack(Item initial_size){
    Stack *s = malloc(sizeof(Stack));
    if(!s){
        fprintf(stderr,"Error : Failied to create the stock \n");
        exit(EXIT_FAILURE);
    }
    s->contents = malloc(initial_size * sizeof(Item));
    if(!s->contentes){
        fprintf(stderr, "Error : Memory allocation failed \n");
        exit(EXIT_FAILURE);
    }
    s->top = -1;
    s->size = initial_size;
    return s;
 } 

 // Emptying the Stack 
 void make_empty(Stack *s){
    s->top = -1;
 }
// is the Stack empty 
bool is_empty(Stack *s){
    return s->top = -1;
}
// Is the Stack full
bool is_full(Stack *s){
    return s->top = s->size - 1;
}
// add element
void push(Stack *s, Item item){
    if(is_full(s)){
        reallocate(s);
    }
    s->contentes[++s->top]= i;
}
// Remove Element 
Item pop(Stack *s){
    if(is_empty(s)){
        stack_underflow();
    }
    return s->contentes[s->top -1];
}
// View the top item 
Item peek(Stack *s){
    if(is_empty(s)){
        stack_underflow();
    }
    return s->contentes[s->top];
}
// Addressing the error of missing element
 static void stack_underflow(void){
    fprintf(stderr , " Stack is Vide \n");
    exit(EXIT_FAILURE);
 }
// Reallacate the stack when it's full
static void reallocate(Stack *stack){
    s->size *= 2;
    s->contentes = realloc(s->contents,s->size * sizeof(Item));
    if(!s->contentes){
        fprintf(stderr,"Error : Memory reallocation failed\n");
    } 
}




