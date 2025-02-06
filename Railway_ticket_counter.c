#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    VIP = 1,
    SENIOR_CITIZEN,
    GENERAL
} PassengerType;

typedef struct Passenger {
    int id;
    PassengerType type;
    char name[50];
    struct Passenger* next;
} Passenger;

Passenger* front = NULL;
Passenger* rear = NULL;

PassengerType get_enum(const char* type_str) {
    if (strcmp(type_str, "VIP") == 0) return VIP;
    if (strcmp(type_str, "SENIOR_CITIZEN") == 0) return SENIOR_CITIZEN;
    return GENERAL;
}

const char* get_string(PassengerType type) {
    switch (type) {
        case VIP: return "VIP";
        case SENIOR_CITIZEN: return "SENIOR_CITIZEN";
        case GENERAL: return "GENERAL";
        default: return "UNKNOWN";
    }
}

Passenger* create_passenger(int id, PassengerType type, char* name) {
    Passenger* new_passenger = (Passenger*)malloc(sizeof(Passenger));
    new_passenger->id = id;
    new_passenger->type = type;
    strcpy(new_passenger->name, name);
    new_passenger->next = NULL;
    return new_passenger;
}

void enqueue(int id, PassengerType type, char* name) {
    Passenger* new_passenger = create_passenger(id, type, name);
    if (front == NULL) {
        front = rear = new_passenger;
    } else {
        Passenger* current = front;
        Passenger* prev = NULL;
        
        while (current != NULL && current->type <= type) {
            prev = current;
            current = current->next;
        }
        // if vip
        if (prev == NULL) {
            new_passenger->next = front;
            front = new_passenger;
        } else {
            prev->next = new_passenger;
            new_passenger->next = current;
            if (current == NULL) rear = new_passenger;
        }
    }
    printf("\nPassenger enqueued successfully: ID %d, Name %s, Type %s", id, name, get_string(type));
}

void dequeue() {
    if (front == NULL) {
        printf("\nQueue is empty");
        return;
    }
    Passenger* temp = front;
    front = front->next;
    printf("\nServing Passenger: ID %d, Name: %s, Type: %s", temp->id, temp->name, get_string(temp->type));
    free(temp);
    if (front == NULL) rear = NULL;
}

void displayQueue() {
    if (front == NULL) {
        printf("\nQueue is empty");
        return;
    }
    printf("\nWaiting Passengers:\n");
    Passenger* current = front;
    while (current != NULL) {
        printf("ID %d, Name: %s, Type: %s\n", current->id, current->name, get_string(current->type));
        current = current->next;
    }
}

int main() {
    int n, choice, id;
    char type[20], name[50];

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter operation (1-Enqueue, 2-Dequeue, 3-Display): ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter ID, Type (VIP/SENIOR_CITIZEN/GENERAL), Name: ");
            scanf("%d %s %s", &id, type, name);
            enqueue(id, get_enum(type), name);
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            displayQueue();
        } else {
            printf("\nInvalid choice");
        }
    }
    return 0;
}
