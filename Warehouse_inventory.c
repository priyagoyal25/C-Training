#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct hashmap{
    char *item;
    int freq;
};

struct hashmap* map;
int map_size = 0;

int map_search(char* item){
    for(int i=0;i<map_size;i++){
        if(strcmp(map[i].item, item) == 0){
            return i;
        }
    }
    return -1;
}

void insert(char* item, int quantity){
    if(map_size>100){
        printf("Capacity full\n");
        exit(0);
    }
    int index = map_search(item);
    if(index != -1){
        map[index].freq += quantity;
    }
    else{
        strcpy(map[map_size].item, item);
        map[map_size].freq = quantity;
        map_size++;
    }
    printf("Added\n");
}

void update(char* item, int quantity){
    int index = map_search(item);
    if(index == -1){
        printf("No item found\n");
        return;
    }
    map[index].freq = quantity;
    printf("Updated\n");
}

void process_query(char* item){
    int index = map_search(item);
    if(index == -1){
        printf("No item found\n");
        return;
    }
    printf("Quantity: %d\n", map[index].freq);
}

void initialise_hashmap(){
    map = (struct hashmap*) malloc(100 * sizeof(struct hashmap));
    for(int i=0;i<100;i++){
        map[i].item = (char *) calloc(100, sizeof(char));
        map[i].freq = 0;
    }
}

int main(){
    initialise_hashmap();
    int no_of_operations;

    printf("Input format:\n");
    printf("Add <item> <quantity>\n");
    printf("Update <item> <quantity>\n");
    printf("Query <item>\n");

    printf("Enter no of operations: ");
    scanf("%d", &no_of_operations);

    char choice[10];
    char item[100];
    int quantity;

    while(no_of_operations--){
        scanf("%s", choice);
        if(choice[0] == 'A'){
            scanf("%s %d", item, &quantity);
            insert(item, quantity);
        }
        else if(choice[0] == 'U'){
            scanf("%s %d", item, &quantity);
            update(item, quantity);
        }
        else if(choice[0] == 'Q'){
            scanf("%s", item);
            process_query(item);
        }
    }
    return 0;
}