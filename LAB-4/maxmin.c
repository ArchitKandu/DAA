//WAP to implement recursive maxmin function and find and compare the execution time with general method of max and min and plot a graph.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
void gmaxmin(int *a,int n){
    int max,min;
    max=min=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>max) max=a[i];
        if(a[i]<min) min=a[i];
    }
}
void rmaxmin(int a[],int low,int high,int *max,int *min)
{ int mid; int max1,min1;
    if (low==high){
        *max= *min=a[low];
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
}
int main(){
    int n;
    printf("Enter size: ");
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
    int max,min;
    max=INT_MIN;
    min=INT_MAX;
    for(int i=0;i<n;i++)
        a[i]=rand();
    clock_t t1,t2;
    double time1,time2;
    t1=clock();
    gmaxmin(a,n);
    t1=clock()-t1;
    t2=clock();
    rmaxmin(a,0,n-1,&max,&min);
    t2=clock()-t2;
    time1=((double)t1/CLOCKS_PER_SEC); 
    time2=((double)t2/CLOCKS_PER_SEC);
    printf("\n---Max Min in %d elements---\n",n);
    printf("GENERAL: %lf \nRECURSION: %lf",time1,time2);
    return 0;
}
