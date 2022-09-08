#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void rmaxmin(int a[],int low,int high,int *max,int *min)
{ int mid; int max1,min1;
    if (low==high){
        *max=*min=a[low];
    }
    else if(low+1 == high)
    {
      if(a[low]>a[high])
        { *max=a[low]; *min=a[high];}
        
      else { *min=a[low]; *max=a[high];}
    }
    else 
      { mid = (low + high)/2;

      rmaxmin(a,low,mid,max,min);
      rmaxmin(a,mid+1,high,&max1,&min1);
      if(max1>*max)
      *max=max1;
      if(min1<*min)
      *min = min1;
    }
    printf("\nMax: %d  Min: %d from %d to %d",*max,*min,low,high);
}
int main(){
    int max,min;
    int a[]={5,1,3,2,4,7,8,6};
    max=min=a[0];
    rmaxmin(a,0,7,&max,&min);
    return 0;
}
