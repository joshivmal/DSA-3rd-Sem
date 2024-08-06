#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data ; 
    struct node *next ;
}s;

void traversal(s *head){
    s *ptr = head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next ;
    }
}

s *reverse(s *head){
    s *prev= NULL ;
    s  *current = head ;
    s *forward = NULL ;

    while(current != NULL){
        forward = current->next ;
        current->next=prev ;
        prev=current ;
        current=forward ;      
    }
    head=prev ;
    return head ;
}

int main(){
    int i=1 ;
    s *head=NULL,*temp;
    while(i){
        s *newnode = (s*)malloc(sizeof(s));
        printf("enter the data of the node ");
        scanf("%d",&newnode->data) ;
        newnode->next=NULL ;
        if(head==NULL){
            head = newnode ;
            temp =  newnode ;
        }
        else{
            temp->next = newnode ;
            temp = newnode; }
        printf("enter 1 or 0 ") ;
        scanf("%d",&i);
    }
    traversal(head);
    head=reverse(head);
    printf("--------\n");
    traversal(head);




    return 0;
}