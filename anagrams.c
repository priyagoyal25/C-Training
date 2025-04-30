#include<stdio.h>
#include<string.h>

int are_anagrams(char string1[], char string2[]){
    int freq_arr[26] = {0};

    if(strlen(string1) != strlen(string2)){
        return 0;
    }

    for(int i=0;i<strlen(string1);i++){
        freq_arr[string1[i]- 'a']++;
    }

    for(int i=0;i<strlen(string2);i++){
        freq_arr[string2[i]- 'a']--;
    }

    for(int i=0;i<26;i++){
        if(freq_arr[i] != 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    char string1[100] = {'\0'};
    char string2[100] = {'\0'};

    printf("Enter first string: ");
    scanf("%s", string1);
    printf("Enter second string: ");
    scanf("%s", string2);

    if(are_anagrams(string1, string2)){
        printf("true");
    }
    else{
        printf("false");
    }

    return 0;
}