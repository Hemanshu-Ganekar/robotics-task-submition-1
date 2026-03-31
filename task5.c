#include<stdio.h>

union binary{
    int num;
    struct{
        unsigned int b0 : 1;
        unsigned int b1 : 1;
        unsigned int b2 : 1;
        unsigned int b3 : 1;
        unsigned int b4 : 1;
        unsigned int b5 : 1;
        unsigned int b6 : 1;
        unsigned int b7 : 1;
        unsigned int b8 : 1;
        unsigned int b9 : 1;
        unsigned int b10 : 1;
        unsigned int b11 : 1;
        unsigned int b12 : 1;
        unsigned int b13 : 1;
        unsigned int b14 : 1;
        unsigned int b15 : 1;
        unsigned int b16 : 1;
        unsigned int b17 : 1;
        unsigned int b18 : 1;
        unsigned int b19 : 1;
        unsigned int b20 : 1;
        unsigned int b21 : 1;
        unsigned int b22 : 1;
        unsigned int b23 : 1;
        unsigned int b24 : 1;
        unsigned int b25 : 1;
        unsigned int b26 : 1;
        unsigned int b27 : 1;
        unsigned int b28 : 1;
        unsigned int b29 : 1;
        unsigned int b30 : 1;
        unsigned int b31 : 1;
        unsigned int b32 : 1;

    } bits;
};

void display(union binary a){
    int arr[32];
    int i=0;
    while(a.num){
        arr[i++] = a.num%2;
        a.num/=2;
    }
    for(int j=i-1;j>=0;j--){
        printf("%d",arr[j]);
    }
    printf("\n");
}

void setABit(union binary* a,int n){
    int temp = 1;
    while(n--)temp = temp<<1;

    (a->num) = (a->num) | temp;
}

void toggleABit(union binary* a,int n){
    int temp = 1;
    while(n--)temp = temp<<1;
    (a->num) = (a->num) ^ temp;
}

void resetABit(union binary* a,int n){
    int temp = 1;
    while(n--) temp =  temp<<1;
    (a->num) = (a->num) & ~temp;
}

int main(){
    union binary b1;
    b1.num = 6;
    display(b1);
    resetABit(&b1,2);
    display(b1);
    return 0;
}