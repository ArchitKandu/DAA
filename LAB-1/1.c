#include<stdio.h>
#include<stdlib.h>
void largesmall(int *arr,int num){
    int max=arr[0];
    int min=arr[0];
    for(int i=1;i<num;i++){
        if(max<arr[i]) max=arr[i];
        if(min>arr[i]) min=arr[i];
    }
    printf("\nMax is: %d\n",max);
    printf("Min is: %d\n",min);
}
void display(int *arr,int n){
    printf("Array is: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}
void user(int *arr,int n){
    printf("\n-----USER INPUT-----\n");
    printf("Enter Numbers: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("\n-----OUTPUT-----\n");
    display(arr,n);
    largesmall(arr,n);
}
void randomnnum(int *arr, int n){
    printf("\n-----RANDOM-----\n");
    for(int i=0;i<n;i++)
        arr[i]=rand();
    printf("\n-----OUTPUT-----\n");
    display(arr,n);
    largesmall(arr,n);
    printf("\n");
}
int main(){
    int n;
    printf("Enter size: ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    user(arr,n);
    randomnnum(arr,n);
    return 0;
}
