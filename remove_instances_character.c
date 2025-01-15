#include<stdio.h>
#include<string.h>

void remove_specified_charcter(char input[], char character){
    int res_index = 0;
    for(int i = 0;i<strlen(input);i++){
        if(input[i] != character){
            input[res_index++] = input[i];
        }
    }
    input[res_index] = '\0';
}

int main(){
    char input[100] = {'\0'};
    char character = '\0';

    printf("ENter input: ");
    scanf("%[^\n]%*c", input);
    
    printf("ENter character: ");
    scanf("%c", &character);

    remove_specified_charcter(input, character);

    printf("Output: %s", input);

    return 0;
}