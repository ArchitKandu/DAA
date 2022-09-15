#include<stdio.h>
#include<stdlib.h>
struct Activities{
    char act;
    int st;
    int ft;
};
typedef struct Activities Act;
void sort(Act *obj, int n){
    int i,j;
    Act temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(obj[j].ft>obj[j+1].ft){
                temp=obj[j];
                obj[j]=obj[j+1];
                obj[j+1]=temp;
            }
        }
    }
}
void printMaxActivities(Act *obj, int n){
    int i,j;
    printf ("\nFollowing activities are selected:\n");
    i=0;
    printf("Activity %c: %d %d\n",obj[i].act,obj[i].st,obj[i].ft);
    for(j=1;j<n;j++){
      if(obj[j].st >= obj[i].ft){
            printf("Activity %c: %d %d\n",obj[j].act,obj[j].st,obj[j].ft);
            i=j;
        }
    }
}
int main(){
    int n;
    char ch='a';
    printf("\nEnter Size: ");
    scanf("%d",&n);
    Act *obj=(Act*)malloc(n*sizeof(Act));
    for(int i=0;i<n;i++){
        printf("Enter start and finish time of Activity %c: ",ch);
        scanf("%d%d",&obj[i].st,&obj[i].ft);
        obj[i].act=ch;
        ch++;
    }
    sort(obj,n);
    printMaxActivities(obj,n);
    return 0;
}
