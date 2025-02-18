#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Movie{
    char* movie_name;
    int rating;
    struct Movie *next;
};

struct Movie *head = NULL;

int is_empty(){
    return head == NULL;
}

struct Movie* create_node(char* name, int rating){
    struct Movie *newnode = (struct Movie*) malloc(sizeof(struct Movie));
    newnode->movie_name = (char*) malloc(100 * sizeof(char));
    strcpy(newnode->movie_name, name);
    newnode->rating = rating;
    newnode->next = NULL;
    return newnode;
}

void insert(char* name, int rating){
    struct Movie *newnode = create_node(name, rating);
    if(head == NULL){
        head = newnode;
        printf("Added\n");
        return;
    }
    struct Movie* cur_node = head, *prev = NULL;
    while(cur_node != NULL && cur_node->rating >= rating){
        prev = cur_node;
        cur_node = cur_node->next;
    }
    if(prev == NULL){
        newnode->next = head;
        head = newnode;
    }
    else{
        newnode->next = prev->next;
        prev->next = newnode;
    }
    printf("Added\n");
}

void remove_movie(char* name){
    if(is_empty()){
        printf("No movies rated\n");
        return;
    }
    struct Movie* cur_node = head;
    struct Movie* prev = NULL;
    while(cur_node != NULL){
        if(strcmp(cur_node->movie_name, name) == 0){
            if(prev == NULL) head = head->next;
            else prev->next = cur_node->next;
            free(cur_node->movie_name);
            free(cur_node);
            printf("Removed\n");
            return;
        }
        prev = cur_node;
        cur_node = cur_node->next;
    }
    printf("No movie rated\n");
}

void highest_rated_movie(){
    if(is_empty()){
        printf("No movies rated\n");
        return;
    }
    printf("(%s, %d)\n", head->movie_name, head->rating);
}

void display(){
    struct Movie* cur_node = head;
    while(cur_node != NULL){
        printf("(%s, %d) -> ", cur_node->movie_name, cur_node->rating);
        cur_node = cur_node->next;
    }
    printf("\n");
}

int main() {
    int no_of_operations;

    printf("Input format:\n");
    printf("rate <movie-name> <rating>\n");
    printf("remove <movie-name>\n");
    printf("top\n");

    printf("Enter no of operations: ");
    scanf("%d", &no_of_operations);

    char choice[10];
    char movie_name[100];
    int rating;

    while(no_of_operations--){
        scanf("%s", choice);
        if(choice[1] == 'a'){
            scanf("%s %d", movie_name, &rating);
            insert(movie_name, rating);
        }
        else if(choice[1] == 'e'){
            scanf("%s", movie_name);
            remove_movie(movie_name);
        }
        else if(choice[0] == 't'){
            highest_rated_movie();
        }
    }

    return 0;
}