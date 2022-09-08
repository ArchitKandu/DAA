#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int partition(int a[100],int low,int high){
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
void quicksort(int a[100],int low,int high){
    int p;
    if(low<=high){
        p=partition(a,low,high);
        quicksort(a,low,p);
        quicksort(a,p+1,high);
    }
}
int main(){
    int n;
    printf("Enter size: ");
    scanf("%d",&n);
    int a[100];
    for(int i=0;i<n;i++)
        a[i]=rand()%100;
    printf("Array is: ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    quicksort(a,0,n-1);
    printf("\nSorted Array is: ");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n\n");
    return 0;
}
