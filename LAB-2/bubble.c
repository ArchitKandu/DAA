#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void bubblesort(int *arr, int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void display(int *arr,int n){
    for(int i=0;i<n;i++)
        arr[i]=rand();
    double rt;
    clock_t t;
    t=clock();
    bubblesort(arr,n);
    t=clock()-t;
    rt=((double)t/CLOCKS_PER_SEC);
    printf("\nTime taken to sort %d random numbers: %f secs",n,rt);
}
int main(){
    int arr1[10000], arr2[20000], arr3[30000], arr4[40000], arr5[50000];
    display(arr1,10000);
    display(arr2,20000);
    display(arr3,30000);
    display(arr4,40000);
    display(arr5,50000);
    printf("\n\n");
    return 0;
}
