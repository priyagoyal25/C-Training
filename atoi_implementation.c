#include<stdio.h>
#include<string.h>

int convert_str_to_int_atoi(char input[]){
    int num = 0, is_negative=0;
    int i=0;

    if(input[0] == '+') i++;
    else if (input[i] == '-') {
        is_negative = 1;
        i++;
    }

    while(input[i] != '\0'){

        if(input[i] <= '0' || input[i] >= '9'){
            return num;
        }
        else if(input[i] >= '0' && input[i] <= '9'){
            num = num*10 + (input[i] - '0');
        }

        i++;
    }
    if(is_negative) num = -num;

    return num;
}


int main(){
    char input[100] = {'\0'};
    int int_num = 0;

    printf("Enter input string: ");
    scanf("%s", input);

    int_num = convert_str_to_int_atoi(input);

    printf("Integer number: %d", int_num);

    return 0;
}