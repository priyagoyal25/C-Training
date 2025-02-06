#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    char data;
    struct Stack* next;
};

int is_empty(struct Stack* top){
    if(top == NULL) return 1;
    return 0;
}

struct Stack* create_node(char ch){
    struct Stack* newnode = (struct Stack*) malloc(sizeof(struct Stack));
    newnode->data = ch;
    newnode->next = NULL;
    return newnode;
}

struct Stack* push(struct Stack* top, char ch){
    struct Stack* newnode = create_node(ch);
    newnode->next = top;
    top = newnode;
    return top;
}

struct Stack* pop(struct Stack* top){
    if(is_empty(top)){
        printf("\nStack underflow");
        return top;
    }
    struct Stack* cur_node = top;
    top = top->next;
    // printf("pop: %c\n", cur_node->data);
    free(cur_node);
    return top;
}

int valid_parenthesis(struct Stack* top, char input[]){
    for(int i=0;i<strlen(input);i++){
        if(input[i] == '('|| input[i] == '[' || input[i] == '{' ){
            top = push(top, input[i]);
        }
        else if(input[i] == ')'){
            if(is_empty(top) || top->data != '(') return 0;
            else top = pop(top);
        }
        else if(input[i] == ']'){
            if(is_empty(top) || top->data != '[') return 0;
            else top = pop(top);
        }
        else if(input[i] == '}'){
            if(is_empty(top) || top->data != '{') return 0;
            else top = pop(top);
        }
    }
    if(is_empty(top)) return 1;
    return 0;
}

int main(){
    struct Stack* top = NULL;
    char input[100000] = {'\0'};

    printf("Enter: ");
    scanf("%s", input);
    if(valid_parenthesis(top, input)){
        printf("true");
    }
    else{
        printf("false");
    }

    return 0;
}