#include<stdio.h>
#include<stdlib.h>
void rmaxmin(int *a,int low, int high, int max, int min){
    if(low==high) max = min = a[low];
    else if(low+1==high){
        if(a[low]>a[high]){
            max=a[low];
            min=a[high];
        }
        else{
            max=a[high];
            min=a[low];
        }
    }
    else{
        int max1,min1,mid;
        max1 = min1 = a[0];
        mid=(low+high)/2;
        rmaxmin(a,low,mid,max,min);
        rmaxmin(a,mid+1,high,max1,min1);
        if(max1>max) max=max1;
        if(min1<min) min=min1;
    }
    printf("\nMax: %d  Min: %d from %d to %d",max,min,low,high);
}
