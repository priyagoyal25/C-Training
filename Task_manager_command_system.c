#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct hashmap{
    char* task;
    int is_completed;
};

struct hashmap* map;
int map_size = 0;

int map_search(char* task){
    for(int i=0;i<map_size;i++){
        if(strcmp(map[i].task, task) == 0) return i;
    }
    return -1;
}

void insert(char *task){
    int index = map_search(task);
    if(index == -1){
        strcpy(map[map_size].task, task);
        map_size++;
        printf("Added\n");
    }
    else{
        printf("Already present\n");
        return;
    }
}

void complete_task(char *task){
    int index = map_search(task);
    if(index == -1){
        printf("Task Not present\n");
        return;
    }
    map[index].is_completed = 1;
    printf("Mark Completed\n");
}

void print_pending(){
    int flag = 0;
    for(int i=0;i<map_size;i++){
        if(!map[i].is_completed){
            printf("%s\n", map[i].task);
            flag = 1;
        }
    }
    if(!flag){
        printf("All tasks completed\n");
    }
}

void initialise_hashmap(){
    map = (struct hashmap*) malloc(100 * sizeof(struct hashmap));
    for(int i=0;i<100;i++){
        map[i].task = (char*) calloc(100, sizeof(char));
        map[i].is_completed = 0;
    }
}

int main(){
    initialise_hashmap();
    int no_of_operations;

    printf("Input format:\n");
    printf("Add <task>\n");
    printf("Complete <task>\n");
    printf("Pending\n");

    printf("Enter no of operations: ");
    scanf("%d", &no_of_operations);

    char choice[10];
    char task[100];

    while(no_of_operations--){
        scanf("%s", choice);
        if(choice[0] == 'A'){
            scanf("%s", task);
            insert(task);
        }
        else if(choice[0] == 'C'){
            scanf("%s", task);
            complete_task(task);
        }
        else if(choice[0] == 'P'){
            print_pending();
        }
    }
    return 0;
}