#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void quicksort(int arr[100], int low, int high){
    int i,j,pivot,temp;
    if(low<high){
        pivot=low;
        i=low;
        j=high;
        while(i<j){
            while(arr[i]<=arr[pivot] && i<high)
                i++;
            while(arr[j]>arr[pivot])
                j--;
            if(i<j){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        temp=arr[pivot];
        arr[pivot]=arr[j];
        arr[j]=temp;
        quicksort(arr,low,j-1);
        quicksort(arr,j+1,high);
    }
}
int main(){
    int i,arr[100],n;
    clock_t t1;
    double time1;
    printf("Enter size of array : ");
    scanf("%d",&n);
    for (i=0;i<n;i++)
        arr[i]=rand()%100;
    printf("\nArray is: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    t1 = clock();
    quicksort(arr,0,n-1);
     t1 = clock() - t1;
    printf("\nSorted Array is: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
     time1 = ((double)t1 / CLOCKS_PER_SEC);
     printf("\nQuickSort: %lf\n\n", time1);
    return 0;
}
