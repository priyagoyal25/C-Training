#include<stdio.h>
#include<string.h>

int count_words(char sentence[100]){
    int count = 0;
    for(int i=0;i<strlen(sentence);i++){
        if(sentence[i] != ' '){
            count++;
            while(sentence[i] != ' '){
                i++;
            }
        }
    }
    return count;
}

int main(){
    char sentence[100] ={'\0'};
    int count = 0;

    printf("Enter sentence: ");
    scanf("%[^\n]%*c", sentence);

    count = count_words(sentence);

    printf("%s\n", sentence);
    printf("Words: %d", count);

    return 0;
}
