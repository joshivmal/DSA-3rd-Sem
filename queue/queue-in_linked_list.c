#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
    }s;

s *front=NULL ;
s*rear=NULL;


void traverse(s*front){

   s *temp=front;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;}
    }
void enqueue(int item){
    s *newnode=(s*)malloc(sizeof(s));
        newnode->data=item;
        if(front==NULL){
            front=newnode;
            rear=newnode;}
        else{
            rear->next=newnode;
            newnode->next=NULL;
            rear=newnode;}
} 

void dequeue(){
    s*temp=front;
    front=front->next;
    free(temp);

}
   



int main(){


    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(10);
    dequeue();
    dequeue();
    dequeue();


    traverse(front);

        
    




    return 0;
}