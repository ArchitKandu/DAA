#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void heapify(int arr[100],int i,int n){
    int largest=i,left=2*i,right=2*i+1,temp=0;
    if(left<=n && arr[left]>arr[largest])
        largest=left;
    if(right<=n && arr[right]>arr[largest])
        largest=right;
    if(largest!=i){
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapify(arr,largest,n);
    }
}
void build_heap(int arr[100],int n){
    for(int i=n/2;i>=0;i--)
        heapify(arr,i,n);
}
int main(){
    int arr[100],n;
    printf("Enter size of array: ");
    scanf("%d",&n);
    srand(time(0));
    for(int i=0;i<n;i++)
        arr[i]=rand()%100;
    printf("\nBefore building heap array is: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    build_heap(arr,n-1);
    printf("\nAfter building heap array is: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n\n");
    return 0;
}
