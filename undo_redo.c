#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int top;
    int capacity;
    char* data;
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
    stack->data = (char*) malloc(sizeof(char) * stack->capacity);
    return stack;
}

void push(struct Stack* stack, char value){
    if(is_full(stack)){
        // realloc
        stack->capacity *= 2;
        stack->data = (char*) realloc(stack->data, sizeof(char)* stack->capacity);
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

void display(struct Stack* stack){
    if(is_empty(stack)){
        printf("Empty\n");
        return;
    }
    for(int i=0;i<=stack->top;i++){
        printf("%c", stack->data[i]);
    }
    printf("\n");
}

void perform_undo(struct Stack* stack1, struct Stack* stack2){
    if(stack1->top != -1){
        char ch = pop(stack1);
        push(stack2, ch);
    }
}

void perform_redo(struct Stack* stack1, struct Stack* stack2){
    if(stack2->top != -1){
        char ch = pop(stack2);
        push(stack1, ch);
    }
}

int main(){
    struct Stack* stack1, *stack2;
    stack1 = initialise_stack();
    stack2 = initialise_stack();

    int choice;
    char ch;
    while(1){
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1: 
                scanf("%c", &ch);
                push(stack1, ch);
                display(stack1);
                break;

            case 2: 
                perform_undo(stack1, stack2);
                display(stack1);
                break;

            case 3: 
                perform_redo(stack1, stack2);
                display(stack1);
                break;
            
            case 4: 
                free(stack1->data);
                free(stack2->data);
                free(stack1);
                free(stack2);
                exit(0);

            default:
                break;
        }
    }

    return 0;
}