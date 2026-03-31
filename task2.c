#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct product{
    int price;
    char name[50];
    int id;
};

struct product* parseString(int count){
    struct product* list = (struct product*) malloc(sizeof(struct product)*count);
    int j=0;
    for (int i = 0; i < count; i++)
    { struct product temp;
      printf("Enter id : ");
      scanf("%d",&temp.id);
      printf("Enter name :");
      scanf("%s",temp.name);
      printf("Enter price :");
      scanf("%d",&temp.price);
      list[i] = temp; 
    }
    return list;
}

void updateProduct(struct product* list,int count,int productId,int newPrice,char newName[]){
    for(int i=0;i<count;i++){
        if((list+i)->id==productId){
            strcpy((list+i)->name,newName);
            (list+i)->price = newPrice;
            return;
        }
    }
}

struct product* highestPrice(struct product* list,int count){
    struct product* temp = &list[0];
    for(int i=0;i<count;i++){
        if((list+i)->price>temp->price){
            temp = (list+i);
        }
    }
    return temp;
}

int main(){
    char s[]= "1,Laptop,75000;2,Mouse,500;3,Keyboard,1500";

    int count;
    printf("Enter the number of product : ");
    scanf("%d",&count);
    struct product* list = parseString(count);
    


    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Price: %d\n",
               list[i].id, list[i].name, list[i].price);
    }
    printf("Update Demonstration :\n");
    updateProduct(list,count,2,400,(list+1)->name);
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Price: %d\n",
               list[i].id, list[i].name, list[i].price);
    }

    printf("highest price Demonstration :\n");
    struct product* temp = highestPrice(list,count);
     printf("ID: %d, Name: %s, Price: %d\n",temp->id, temp->name, temp->price);
    free(list);
    return 0;
}