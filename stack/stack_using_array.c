#include<stdio.h>
int top=-1,n;

int isempty(int top){
    if(top==-1){
        return 1;
    }
    return 0;
}

int isFull(int top){
    if(top==n-1){
        printf("overflow\n");
        return 0;
    }
    else{
        return 1;
    }
}

int push(int top,int item,int arr[]){
    if(isFull(top)){
    top++;
    arr[top]=item;
    return top;}
}
int pop(int top,int arr[]){
    printf("popped element is %d\n",arr[top]);
    top--;
    return top;
}

void traverse(int arr[],int top){
    int temp=top;
    while(temp!=-1){
        printf("%d\n",arr[temp]);
        temp--;
    }}


int main(){
    printf("enter the size of stack  ");
    scanf("%d",&n);
    int arr[n];
    top=push(top,5,arr);
    top=push(top,6,arr);
    top=push(top,7,arr);
    top=push(top,8,arr);
    top=push(top,9,arr);
    top=pop(top,arr);
    traverse(arr,top);

    





    return 0;
}
