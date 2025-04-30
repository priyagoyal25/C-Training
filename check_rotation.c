#include<stdio.h>
#include<string.h>

int getlength(char str[]){
    int length = 0;
    while(str[length] != '\0'){
        length++;
    }
    return length;
}

void concate_string(char concatenated_string[], char str1[]){
    int str_index = 0;
    int concat_index = 0;

    while(concatenated_string[concat_index] != '\0'){
        concat_index++;
    }
    while(str1[str_index] != '\0'){
        concatenated_string[concat_index] = str1[str_index];
        str_index++;
        concat_index++;
    }
    concatenated_string[concat_index] = '\0';
}

int is_substr(int length1, int length2, char str1[], char str2[]){
    int i,j;

    for(i=0;i<length1;i++){
        if(str1[i] == str2[0]){
            for(j=0;j<length2;j++){
                if(str1[i+j] != str2[j]){
                    return 0;
                }
            }
            if(str2[j] == '\0'){
                return 1;
            }
        }
    }

    return 0;
}

int check_rotation(char str1[100], char str2[100]){
    int length1 = 0, length2 = 0;

    length1 = getlength(str1);
    length2 = getlength(str2);

    if(length1 != length2){
        return 0;
    }

    char concatenated_string[2 * length1 +1];
    concatenated_string[0] = '\0';

    concate_string(concatenated_string, str1);
    concate_string(concatenated_string, str1);

    if(is_substr(length1, length2, concatenated_string, str2)){
        return 1;
    }

    return 0;
}

int main(){
    char str1[100]={'\0'};
    char str2[100]={'\0'};

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);


    if(check_rotation(str1, str2)){
        printf("true\n");
    }
    else{
        printf("false\n");
    }

    return 0;
}