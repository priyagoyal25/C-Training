#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void input_without_space(char input[100]){
    printf("Enter input without spaces: ");
    scanf("%s", input);

    printf("\nYou entered: %s", input);
}

void input_with_space(char input[100]){
    getchar();
    printf("Enter input with spaces: ");
    scanf("%[^\n]%*c", input);

    printf("\nYou entered: %s", input);
}

void input_with_comma(char input[100]){
    getchar();
    printf("Enter input with commas: ");
    scanf("%[^\n]%*c", input);

    printf("\nYou entered: %s", input);
}

void input_only_digit(char input[100]){
    getchar();
    printf("Enter input only digit: ");
    scanf("%[^\n]%*c", input);

    for(int index=0;index<strlen(input);index++){
        if(input[index] <= '0' || input[index] >= '9'){
            printf("\nInvalid\n");
            return;
        }
    }

    printf("\nYou entered: %s", input);
}

void input_only_alphabet(char input[100]){
    getchar();
    printf("Enter input only alphabets: ");
    scanf("%[^\n]%*c", input);

    for(int index=0;index<strlen(input);index++){
        if(input[index] <= 'A' || (input[index] >= 'Z' && input[index] <= 'a') || input[index] >= 'z'){
            printf("\nInvalid\n");
            return;
        }
    }
    printf("\nYou entered: %s", input);
}


int main(){
    int choice;
    char input[100];

    while(1){
        printf("\n----Menu----");
        printf("\n1. Input without spaces");
        printf("\n2. Input with spaces");
        printf("\n3. Input with commas");
        printf("\n4. Input only digits");
        printf("\n5. Input only alphabets");
        printf("\n6. Exit");

        printf("\nEnter choice: ");

        if(scanf("%d", &choice) != 1) continue;

        switch(choice){
            case 1: input_without_space(input); 
            break;
            case 2: input_with_space(input); break;
            case 3: input_with_comma(input); break;
            case 4: input_only_digit(input); break;
            case 5: input_only_alphabet(input); break;
            case 6: printf("\nExiting..\n"); exit(0);
            default: printf("\nInvalid choice: \n");
        }
    }

    return 0;
}