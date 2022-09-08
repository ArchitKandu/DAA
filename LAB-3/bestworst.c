#include<stdio.h>
#include<stdlib.h>
#include<time.h>
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
int main(){
    int arr[50000],rarr[50000];
    int i,j;
    clock_t t1,t2;
    double time1,time2;
    for(i=0;i<50000;i++)
        arr[i]=rand();
    insertionsort(arr,50000);
    t1=clock();
    insertionsort(arr,50000);
    t1=clock()-t1;
    insertionsort(arr,50000);
    for(i=0,j=50000;i<50000;i++,j--)
        rarr[j]=arr[i];
    t2=clock();
    insertionsort(rarr,50000);
    t2=clock()-t2;
    time1=((double)t1/CLOCKS_PER_SEC);
    time2=((double)t2/CLOCKS_PER_SEC);
    printf("\nBest case time: %f",time1);
    printf("\nWorst case time: %f\n\n",time2);
    return 0;
}
