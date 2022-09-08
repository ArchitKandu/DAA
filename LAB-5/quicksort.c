#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(int *a,int low,int high){
    int temp,pivot=a[low];
    int i=low,j=high;
    while(i<j){
        while(a[i]<=pivot){
            i++;
        }
        while(a[j] > pivot){
            j--;
        }
        if (i<j){
            temp=a[i];        
            a[i]=a[j];
            a[j]=temp;
        }                                 
    }
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}
void quicksort(int *a,int low,int high){
    if(low<=high){
        int p=partition(a,low,high);
        quicksort(a,low,p);
        quicksort(a,p+1,high);
    }
}
int main(){
    int n;
    double time;
    clock_t t;
    printf("\nEnter size: ");
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        a[i]=rand();
    t=clock();
    quicksort(a,0,n-1);
    t=clock()-t;
    time=((double)t/CLOCKS_PER_SEC);
    printf("TIME TAKEN: %f",time);
    return 0;
}
