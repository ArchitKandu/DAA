#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void insertionsort(int *arr, int n){
    int i,key,j;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
void display(int *arr,int n){
    for(int i=0;i<n;i++)
        arr[i]=rand();
    double rt;
    clock_t t;
    t=clock();
    insertionsort(arr,n);
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
