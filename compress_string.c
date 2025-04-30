#include<stdio.h>
#include<string.h>

void compress_string(char string[], char result[]){
    int res_index = 0;
    int i = 0;
    char str_count[50] = {'\0'};
    while(string[i] != '\0'){
        result[res_index] = string[i];
        i++;
        int count = 1;
        while(i<strlen(string) && string[i] == result[res_index]){
            count++;
            i++;
        }
        res_index++;      
        sprintf(str_count, "%d", count);
    
        for (int j = 0; str_count[j] != '\0'; j++) { 
            result[res_index++] = str_count[j]; 
        }
    }
    result[res_index] = '\0';

}

int main(){
    char string[100] = {'\0'};
    char result[100] = {'\0'};

    printf("Enter string: ");
    scanf("%s", string);

    compress_string(string, result);

    if(strlen(result) <= strlen(string)){
        printf("Compressed string: %s", result);
    }
    else{
        printf("Compressed string: %s", string);
    }

    return 0;
}