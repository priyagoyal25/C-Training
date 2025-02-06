#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int top;
    int capacity;
    int* data;
};

int is_empty(struct Stack* stack){
    if(stack->top == -1) return 1;
    return 0;
}

int is_full(struct Stack* stack){
    if(stack->top == stack->capacity-1) return 1;
    return 0;
}

struct Stack* initialise_stack(){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = 10;
    stack->data = (int*) malloc(sizeof(int) * stack->capacity);
    return stack;
}

void push(struct Stack* stack, int value){
    if(is_full(stack)){
        // realloc
        stack->capacity *= 2;
        stack->data = (int*) realloc(stack->data, sizeof(int)* stack->capacity);
    }
    stack->top++;
    stack->data[stack->top] = value;    
}

int pop(struct Stack* stack){
    if(is_empty(stack)) return -1;

    int item = stack->data[stack->top];
    stack->top--;
    return item;
}

int* stockspan(struct Stack* stack1, struct Stack* stack2, int arr[], int size){
    int * result = (int *) malloc(sizeof(int) * size);

    // initialise result with 1
    for(int i=0;i<size;i++){
        result[i] = 1;
    }
    // check span and store result
    for(int i=0;i<size;i++){
        while(!is_empty(stack1) && stack1->data[stack1->top] < arr[i]){
            result[i]++;
            int item = pop(stack1);
            push(stack2, item);
        }
        while(!is_empty(stack2)){
            int item = pop(stack2);
            push(stack1, item);
        }
        push(stack1, arr[i]);
    }

    return result;
}

int main(){
    struct Stack* stack1, *stack2;
    stack1 = initialise_stack();
    stack2 = initialise_stack();

    int size = 0;
    int* input = (int *) malloc(sizeof(int) * 10000);

    while(1){
        scanf("%d", &input[size++]);
        char ch = getchar();
        if(ch == '\n' || ch == EOF) break;
    }

    for(int i=0;i<size;i++){
        printf("%d ", input[i]);
    }
    printf("\n");

    int * result = stockspan(stack1, stack2, input, size);
    for(int i=0;i<size;i++){
        printf("%d ", result[i]);
    }

    return 0;
}