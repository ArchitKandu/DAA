#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int *a, int low, int mid, int high)
{
    int i=low,j=mid+1,k=low;
    int c[10000000];
    while (i<=mid && j<=high){
        if (a[i]<a[j])
            c[k++]=a[i++];
        else
            c[k++]=a[j++];
    }
    while (i <= mid){
        c[k++]=a[i++];
    }
    while (j<=high){
        c[k++]=a[j++];
    }
    for(i=low;i<=high;i++){
        a[i] = c[i];
    }
}
void mergesort(int *a,int p,int r){
    int q;
    if(p<r){
        q=(p+r)/2;
        mergesort(a,p,q);
        mergesort(a,q+1,r);
        merge(a,p,q,r);
    }
}
int main(){
    int n;
    float time;
    clock_t t;
    printf("\nEnter size: ");
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        a[i]=rand();
    t=clock();
    mergesort(a,0,n-1);
    t=clock()-t;
    time=((float)t/CLOCKS_PER_SEC);
    printf("TIME TAKEN: %f",time);
    return 0;
}
