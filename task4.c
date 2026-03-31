#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int main(){
    printf("int  \n");
    printf("\tmax : %d, min : %d\n",INT_MAX,INT_MIN);
    printf("  if limits are cross\n");
    printf("\tmax : %d, min : %d\n",INT_MAX+10,INT_MIN-10);
    printf("“unsigned int  \n");
    printf("\tmax : %u, min : %u\n",UINT_MAX,0);
    printf("  if limits are cross\n");
    printf("\tmax : %u, min : %u\n",UINT_MAX+10,0-10);
    printf("short  \n");
    printf("\tmax : %hd, min : %hd\n",SHRT_MAX,SHRT_MIN);
    printf("  if limits are cross\n");
    printf("\tmax : %u, min : %u\n",SHRT_MAX+10,SHRT_MIN-10);
    printf("Long  \n");
    printf("\tmax : %ld, min : %ld\n",LONG_MAX,LONG_MIN);
    printf("  if limits are cross\n");
    printf("\tmax : %ld, min : %ld\n",LONG_MAX+10,LONG_MIN-10);
    return 0;
}