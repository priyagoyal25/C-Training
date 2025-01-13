#include<stdio.h>
#include<string.h>

void remove_duplicates(char str[100]){
    int freq_arr[26] ={0}; // 0 means no duplicate ,1 means already in the string don't add that character again
    int res_index = 0;

    for(int i=0;i<strlen(str);i++){
        if(freq_arr[str[i]-'a'] == 0){
            freq_arr[str[i]-'a'] = 1;
            str[res_index] = str[i];
            res_index++;
        }
    }
    str[res_index] = '\0';
}
 
int main(){
    char str[100] ={'\0'};

    printf("Enter string: ");
    scanf("%s", str);

    remove_duplicates(str);

    printf("%s", str);

    return 0;
}
