#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int top;
    int capacity;
    int *data;
};

struct Stack* stack = NULL;
int *sorted_data;
int sorted_data_index = 0;

int is_empty(){
    return stack->top == -1;
}

int is_full(){
    return stack->top == stack->capacity-1;
}

void push(int value){
    if(is_full()){
        printf("Stack is full\n");
        return;
    }

    stack->top++;
    stack->data[stack->top] = value;
    printf("Added\n");

    int i = sorted_data_index-1;
    while(i >= 0 && sorted_data[i] > value){
        sorted_data[i+1] = sorted_data[i];
        i--;
    }
    sorted_data[i+1] = value;
    sorted_data_index++;
}

void pop(){
    if(is_empty()){
        printf("Nothing to delete\n");
        return;
    }
    int item = stack->data[stack->top--];

    int i;
    for(i=0;i<sorted_data_index;i++){
        if(sorted_data[i] == item) break;
    }

    for(i;i<sorted_data_index;i++){
        sorted_data[i] = sorted_data[i+1];
    }
    sorted_data_index--;
    printf("Deleted\n");
}

void display(){
    if(is_empty()){
        printf("No bookmarks\n");
        return;
    }

    for(int i = 0;i<=stack->top;i++){
        printf("%d ", sorted_data[i]);
    }
    printf("\n");
}

void initialise_stack(){
    stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = 100;
    stack->data = (int *) malloc(stack->capacity * sizeof(int));
}

int main(){
    initialise_stack();
    sorted_data = (int *) malloc(stack->capacity * sizeof(int));

    int no_of_operations;

    printf("Input format:\n");
    printf("Bookmark <page_no>\n");
    printf("Delete\n");
    printf("List\n");

    printf("Enter no of operations: ");
    scanf("%d", &no_of_operations);

    char choice[10];
    int page_no;

    while(no_of_operations--){
        scanf("%s", choice);
        if(choice[0] == 'B'){
            scanf("%d", &page_no);
            push(page_no);
        }
        else if(choice[0] == 'D') pop();
        else if(choice[0] == 'L') display();
    }
    return 0;
}