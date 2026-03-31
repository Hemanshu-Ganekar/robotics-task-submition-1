#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct product{
    int price;
    char name[50];
    int id;
};

struct product* parseString(char s[],int n,int* count){
    int start = 0;
    struct product temp;
    struct product* list = NULL;
    *count = 0;
    int j=0;

    for (int i = 0; i <= n; i++)
    {
        if(s[i]==',' && j==0){
            int num = 0;
            for(int k=start; k<i; k++){
                num = num*10 + (s[k]-'0');
            }
            temp.id = num;
            j++;
            start = i+1;
        }
        else if(s[i]==',' && j==1){
            int k=0;
            for(int l=start; l<i; l++){
                temp.name[k++] = s[l];
            }
            temp.name[k] = '\0';
            j++;
            start = i+1;
        }
        else if((s[i]==';' || s[i]=='\0') && j==2){
            int num = 0;
            for(int k=start; k<i; k++){
                num = num*10 + (s[k]-'0');
            }
            temp.price = num;

            (*count)++;
            list = realloc(list, sizeof(struct product) * (*count));
            list[*count-1] = temp;

            j = 0;
            start = i+1;
        }
    }
    return list;
}

int main(){
    char s[]= "1,Laptop,75000;2,Mouse,500;3,Keyboard,1500";

    int count;
    struct product* list = parseString(s, strlen(s), &count);

    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Price: %d\n",
               list[i].id, list[i].name, list[i].price);
    }
    printf("Update Demonstration :\n");
   free(list);
    return 0;
}