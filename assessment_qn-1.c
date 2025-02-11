#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{
    ONE,
    LOG_N,
    SQRT_N,
    N,
    N_LOG_N,
    N_K,
    TWO_N,
    FACT_N
}Complexity;

typedef struct Node{
    Complexity time_complexity;
    Complexity space_complexity;
    struct Node *next; 
}Node;

Complexity get_enum(char* input){
    if(strcmp("1", input) == 0) return ONE;
    if(strcmp("logn", input) == 0) return LOG_N;
    if(strcmp("sqrt(n)", input) == 0) return SQRT_N;
    if(strcmp("n", input) == 0) return N;
    if(strcmp("nlogn", input) == 0) return N_LOG_N;
    if(strcmp("n^k", input) == 0) return N_K;
    if(strcmp("2^n", input) == 0) return TWO_N;
    return FACT_N;
}

char * mapFromComplexity(Complexity complexity){
    switch (complexity){
        case ONE: return "1";
        case LOG_N: return "logn";
        case SQRT_N: return "sqrt(n)";
        case N: return "n";
        case N_LOG_N: return "nlogn";
        case N_K: return "n^k";
        case TWO_N: return "2^n";
        default: return "!n";
    }
}

Node* create_node(Complexity time, Complexity space){
    Node* newnode = (Node*) malloc(sizeof(Node));
    newnode->time_complexity = time;
    newnode->space_complexity = space;
    newnode->next = NULL;
    return newnode;
}

void insert(Node** head, char* time, char* space){
    Node* newnode = create_node(get_enum(time), get_enum(space));
    if(*head == NULL){
        *head = newnode;
        return;
    }
    Node* cur_node = *head;

    while(cur_node->next != NULL){
        cur_node = cur_node->next;
    }
    cur_node->next = newnode;
}

void get_input(Node** head){
    char* time = (char *) malloc(10 * sizeof(char));
    char* space = (char *) malloc(10 * sizeof(char));
    int no_of_operations;
    scanf("%d", &no_of_operations);

    while(no_of_operations--){
        scanf("%s %s", time,space);
        insert(head, time, space);
    }
       
}

void sort(Node** head){
    Node* i = *head;
    Node* j = *head;

    for(i = *head; i != NULL && i->next != NULL; i = i->next){
        for(j = *head; j != NULL && j->next != NULL; j = j->next){
            if(j->time_complexity > j->next->time_complexity){
                Complexity temp = j->time_complexity;
                j->time_complexity = j->next->time_complexity;
                j->next->time_complexity = temp;

                temp = j->space_complexity;
                j->space_complexity = j->next->space_complexity;
                j->next->space_complexity = temp;
            }
            else if(j->time_complexity == j->next->time_complexity){
                if(j->space_complexity > j->next->space_complexity){
                    Complexity temp = j->time_complexity;
                    j->time_complexity = j->next->time_complexity;
                    j->next->time_complexity = temp;
    
                    temp = j->space_complexity;
                    j->space_complexity = j->next->space_complexity;
                    j->next->space_complexity = temp;
                }
            }
        }
    }
}

void print(Node* head){
    Node* cur_node = head;
    printf("\n");
    while(cur_node != NULL){
        printf("%s %s\n", mapFromComplexity(cur_node->time_complexity), mapFromComplexity(cur_node->space_complexity));
        cur_node = cur_node->next;
    }
}

int main(){
    Node* head = NULL;
    get_input(&head);
    sort(&head);
    print(head);
    return 0;
}