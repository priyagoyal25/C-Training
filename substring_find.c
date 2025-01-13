#include<stdio.h>
#include<string.h>


int is_substring(char str[100], char substr[100]){
    int i, j;
    int substr_index = -1;

    for(i = 0;i<strlen(str);i++){
        if(str[i] == substr[0]){
            for(j=0;j<strlen(substr);j++){
                if(str[i+j] != substr[j]){
                    break;
                }
            }
            if(substr[j] == '\0'){
                substr_index = i;
            }
        }
    }
    return substr_index;
}

int main(){
    char str[100] = {'\0'};
    char substr[100] = {'\0'};
    int substr_index = -1;

    printf("Enter string: ");
    scanf("%[^\n]%*c", str);

    printf("Enter sub-string: ");
    scanf("%[^\n]%*c", substr);

    substr_index = is_substring(str, substr);

    printf("%d", substr_index);

    return 0;
}