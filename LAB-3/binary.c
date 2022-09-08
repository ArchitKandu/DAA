#include<stdio.h>
#include<stdlib.h>
int * insertionsort(int *arr, int n){
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
    return arr;
}
int binarysearch(int *arr,int item,int low,int high){
    if(low==high){
        if(arr[low]==item) return low;
        else return -1;
    }
    else{
        int mid=(low+high)/2;
        if(arr[mid]==item) return mid;
        else{
            if(item<arr[mid]) return binarysearch(arr,item,low,mid-1);
            else return binarysearch(arr,item,mid,high);
        }
    }
}
int main(){
    int *arr;
    int *newarr;
    int n,item,idx;
    printf("\nEnter Size: ");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    newarr=(int *)malloc(n*sizeof(int));
    printf("Enter data: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    newarr=insertionsort(arr,n);
    printf("After sorting array is: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\nEnter item to search: ");
    scanf("%d",&item);
    idx=binarysearch(arr,item,0,n-1);
    printf("After sorting found element at index: %d",idx);
    return 0;
}
