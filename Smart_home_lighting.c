#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct hashmap{
    int room_no;
    int status;
};

struct hashmap* map;
int map_size = 0;

int map_search(int room){
    for(int i=0;i<map_size;i++){
        if(map[i].room_no == room) return i;
    }
    return -1;
}

void insert(int room, int status){
    int index = map_search(room);
    if(index == -1){
        map[map_size].room_no = room;
        map[map_size].status = status;
        map_size++;
    }
    else{
        map[index].status = status;
    }
    printf("Done\n");
}

void get_status(int room){
    int index = map_search(room);
    if(index == -1 || map[index].status == 0){
        printf("Status: OFF\n");
    }
    else{
        printf("Status: ON\n");
    }
}

void initialise_hashmap(){
    map = (struct hashmap*) malloc(100 * sizeof(struct hashmap));
    for(int i=0;i<100;i++){
        map[i].room_no = -1;
        map[i].status = 0;
    }
}

int main(){
    initialise_hashmap();
    int no_of_operations;

    printf("Input format:\n");
    printf("Turn ON <room_no>\n");
    printf("Turn OFF <room_no>\n");
    printf("Status <room_no>\n");

    printf("Enter no of operations: ");
    scanf("%d", &no_of_operations);

    char choice[10];
    char status[5];
    int room;

    while(no_of_operations--){
        scanf("%s", choice);
        if(choice[0] == 'T'){
            scanf("%s %d", status, &room);
            if(status[1] == 'N') insert(room, 1);
            else insert(room, 0);
        }
        else if(choice[0] == 'S'){
            scanf("%d", &room);
            get_status(room);
        }
    }
    return 0;
}