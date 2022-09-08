#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void sort(int *arr, int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[i];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main(){
    int arr1[10], arr2[1000], arr3[10000];
    clock_t t1,t2,t3;
    double t_1,t_2,t_3;
    for(int i=0;i<10;i++)
        arr1[i]=rand();
    for(int i=0;i<1000;i++)
        arr2[i]=rand();
    for(int i=0;i<10000;i++)
        arr3[i]=rand();
    t1=clock();
    sort(arr1,10);
    t1=clock()-t1;
    t2=clock();
    sort(arr2,1000);
    t2=clock()-t2;
    t3=clock();
    sort(arr3,10000);
    t3=clock()-t3;
    t_1=((double)t1/CLOCKS_PER_SEC);
    t_2=((double)t2/CLOCKS_PER_SEC);
    t_3=((double)t3/CLOCKS_PER_SEC);
    printf("\nTime taken to sort 10 random numbers: %f",t_1);
    printf("\nTime taken to sort 1000 random numbers: %f",t_2);
    printf("\nTime taken to sort 10000 random numbers: %f\n\n",t_3);
    return 0;
}
