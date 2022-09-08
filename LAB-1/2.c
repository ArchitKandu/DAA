#include<stdio.h>
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    int a,b,c;
    printf("Enter three numbers: ");
    scanf("%d%d%d",&a,&b,&c);
    printf("\n-----INITIAL-----\n");
    printf("a: %d, b: %d, c: %d",a,b,c);
    swap(&b,&c);
    swap(&a,&b);
    printf("\n-----FINAL-----\n");
    printf("a: %d, b: %d, c: %d\n\n",a,b,c);
    return 0;
}
