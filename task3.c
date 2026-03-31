#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int main(){
    FILE* fp1 = fopen("./file1.txt","r");
    if(fp1 == NULL){
    printf("Error opening file\n");
    return 1;
   }
   int min=INT_MAX,max=INT_MIN,sum=0;
    int num = 0;
    int* arr = malloc(sizeof(int)*0);
    int count=0;
    while(fscanf(fp1,"%d",&num)!=EOF){
        count++;
        arr = realloc(arr,(sizeof(int)*count));
        *(arr+count-1) = num;
        if(min>num) min = num;
        if(max<num) max = num;
        sum+=num;
    }
    fclose(fp1);
    FILE* fp2 = fopen("./file2.txt","w");
    fprintf(fp2,"sum : %d\nmin : %d\nmax : %d",sum,min,max);
    fclose(fp2);
    for(int i=0;i<count;i++) printf("%d ",*(arr+i));
}