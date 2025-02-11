#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int top;
    int capacity;
    int* array;
};

int is_empty(struct Stack* stack){
    return stack->top == -1;
}

int is_full(struct Stack* stack){
    return stack->top >= stack->capacity-1;
}

void push(struct Stack* stack, int value){
    if(is_full(stack)){
        exit(0);
    }
    stack->top++;
    stack->array[stack->top] = value;
}

int pop(struct Stack* stack){
    if(is_empty(stack)){
        return -1;
    }
    int item = stack->array[stack->top];
    stack->top--;
    return item;
}

void peek(struct Stack* stack){
    if(is_empty(stack)){
        printf("None\n");
        return;
    }
    printf("%d\n", stack->array[stack->top]);
}

int dequeue(struct Stack* stack) {
    if (is_empty(stack)) {
        return -1;
    }
    int item = pop(stack);

    if (is_empty(stack)) {
        return item;
    }

    int res = dequeue(stack);
    push(stack, item);
    return res;
}

struct Stack* create_stack(){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = 100;
    stack->array = (int*) malloc(sizeof(int) * 100);
    return stack;
}

int main(){
    struct Stack *stack = create_stack();

    int choice, value, no_of_operations;
    int item;
    scanf("%d", &no_of_operations);

    while(no_of_operations--){   
        scanf("%d", &choice);
        switch(choice){
            case 1: 
            scanf("%d", &value);
            push(stack, value);
            break;
            case 2: item = dequeue(stack);
            if(item == -1) printf("None\n");
            else printf("%d\n", item);
            break;
            case 3: peek(stack);
            break;
            case 4: 
            if(is_empty(stack)){
                printf("true\n");
            }
            else{
                printf("false\n");
            }
            break;
        }
    }
    return 0;
} 