#include<stdio.h>

void reverse(int n, int arr[n], int start, int end){
    
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void ackw_rotate(int n, int k, int arr[n]){
    // Handle the case where k > size of array => k=7, n=5 then shift 7%5=2 now k=2
    k %= n;
    reverse(n, arr, 0, k-1);

    reverse(n, arr, k, n-1);
   
    reverse(n, arr, 0, n-1);
    
}

int main(){
    int n,k;

    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");

    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    ackw_rotate(n,k,arr);

   for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}