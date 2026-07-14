#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 5
#define EXIT INT_MIN

typedef struct {
    int items[MAX_SIZE];
    int top;
    int is_initialized;
} Stack;

void InitStack(Stack *s) {
    if(s->is_initialized) {
        printf("Stack Already Initialized. Stack Initialization: Failed.\n");
    } else {
        s->top = -1;
        s->is_initialized = 1;
        printf("Stack Initialization: Success\n");
    }
}

int IsFull(Stack *s) {
    return s->top == (MAX_SIZE - 1);
}

int IsEmpty(Stack *s) {
    return s->top == -1;
}

void Push(Stack *s, int item) {
    if(IsFull(s)) {
        printf("Stack Is Full. Push: Failed.\n");
    } else {
        s->items[++(s->top)] = item;
        printf("Item Added. Push: Success.\n");
    }
}

int Pop(Stack *s) {
    if(IsEmpty(s)) {
        return EXIT;
    } else { 
        return s->items[(s->top)--];
    }
}

int Peek(Stack *s) {
    if(IsEmpty(s)) {
        return EXIT;
    } else { 
        return s->items[s->top];
    }
}

int main() {

    Stack number_stack = {0};

    InitStack(&number_stack);

    Push(&number_stack, 243);
    printf("Peek: %d\n", Peek(&number_stack));
    Push(&number_stack, 893);
    printf("Peek: %d\n", Peek(&number_stack));
    Push(&number_stack, 232);
    printf("Peek: %d\n", Peek(&number_stack));
    Push(&number_stack, 765);
    printf("Peek: %d\n", Peek(&number_stack));
    Push(&number_stack, 123);
    printf("Peek: %d\n", Peek(&number_stack));
    Push(&number_stack, 400);
    printf("Peek: %d\n", Peek(&number_stack));

    printf("Numbers: ");
    while(Pop(&number_stack) != EXIT) {
        printf("%d ", Pop(&number_stack));
    }
    printf("\n");

    return 0;
}