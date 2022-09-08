#include<stdio.h>
#include<stdlib.h>
void display(int *arr,int n){
    printf("\nArray is: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
void seclargesmall(int *arr, int n, int max, int min){
    int s_max=arr[0];
    int s_min=arr[0];
    for(int i=0;i<n;i++){
        if(s_max<arr[i] && arr[i]!=max) s_max=arr[i];
        if(s_min>arr[i] && arr[i]!=min) s_min=arr[i];
    }
    display(arr,n);
    printf("\nSecond Largest is: %d\n", s_max);
    printf("Second Smallest is: %d\n\n", s_min);
}
void largesmall(int *arr,int n){
    int max=arr[0];
    int min=arr[0];
    for(int i=1;i<n;i++){
        if(max<arr[i]) max=arr[i];
        if(min>arr[i]) min=arr[i];
    }
    seclargesmall(arr,n,max,min);
}
int main(){
    int n;
    printf("Enter Size: ");
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    printf("Enter numbers: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    largesmall(arr,n);
    return 0;
}
