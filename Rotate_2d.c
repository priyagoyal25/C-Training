// Rotate row-wise
#include <stdio.h>

void ackw_rotate_column(int size, int arr[size][size]){
    int k;
    printf("Enter value of k: ");
    scanf("%d", &k);
    int temp[size][size];
    
    if(k<size){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                int index = (j+k)%size;
                temp[i][j] = arr[i][index];
            }
        }
    }
    
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ", temp[i][j]);
        }
        printf("\n");
    }
}

void ckw_rotate_column(int size, int arr[size][size]){
    int k;
    printf("Enter value of k: ");
    scanf("%d", &k);
    int temp[size][size];
    
    if(k<size){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                int index = (j+k)%size;
                temp[i][index] = arr[i][j];
            }
        }
    }
    
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ", temp[i][j]);
        }
        printf("\n");
    }
}

void ackw_rotate_row(int size, int arr[size][size]){
    int k;
    printf("Enter value of k: ");
    scanf("%d", &k);
    int temp[size][size];
    
    if(k<size){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                int index = (i+k)%size;
                temp[i][j] = arr[index][j];
            }
        }
    }
    
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ", temp[i][j]);
        }
        printf("\n");
    }
}

void ckw_rotate_row(int size, int arr[size][size]){
    int k;
    printf("Enter value of k: ");
    scanf("%d", &k);
    int temp[size][size];
    
    if(k<size){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                int index = (i+k)%size;
                temp[index][j] = arr[i][j];
            }
        }
    }
    
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%d ", temp[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    
    
    int arr[size][size];
    printf("Enter elements:\n");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\nRotation column wise clockwise\n");
    ckw_rotate_column(size, arr);

    printf("\nRotation column wise anti-clockwise\n");
    ackw_rotate_column(size, arr);

    printf("\nRotation row wise clockwise\n");
    ckw_rotate_row(size, arr);

    printf("\nRotation row wise anti-clockwise\n");
    ackw_rotate_row(size, arr);

    return 0;
}