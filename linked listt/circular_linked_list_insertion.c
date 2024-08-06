#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}s;

s *insertatfirst(s *head,int data){     //insert at first complexity= O(1)
    s *newnode=(s*)malloc(sizeof(s));
    newnode->data=data;
    s *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    head=newnode;

    return(head);}

s *insertatend(s *head,int data){       //insert at end complexity= O(1)
    s *newnode=(s*)malloc(sizeof(s));
    newnode->data=data;
    s *temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    return head;
}

s *insertatindex(s *head,int ind){          // insert at the index complexity =O(n)
    s *newnode=(s*)malloc(sizeof(s));
    newnode->data=92;
    s *temp=head;
    int i=0;
    while(i<ind-1){
        temp=temp->next;
        i++;
    }
    s *hell=temp->next;
    temp->next=newnode;
    newnode->next=hell;
    return head;


}

void insertafteranode(s*node){      // insert after a givem node = O(1)
    s *newnode=(s*)malloc(sizeof(s));
    newnode->data=99;
    newnode->next=node->next;
    node->next=newnode;


}


 void traverseCLL(s* head){
    s *temp=head;
    // printf("%d\n",temp->data);
    // while(temp->next!=head){
    //     temp=temp->next;
    //     printf("%d\n",temp->data);

    do{
        printf("%d\n",temp->data);
        temp=temp->next;
        }while(temp!=head);

    }

 

int main(){
    s *head,*second,*third,*fourth;

    head=(s*)malloc(sizeof(s));
    second=(s*)malloc(sizeof(s));
    third=(s*)malloc(sizeof(s));
    fourth=(s*)malloc(sizeof(s));

    head->data=5;
    head->next=second;

    second->data=6;
    second->next=third;

    third->data=7;
    third->next=fourth;

    fourth->data=8;
    fourth->next=head;

    traverseCLL(head);
    printf("after the updation\n");
    head=insertatfirst(head,56);
    head=insertatend(head,45);
    head=insertatindex(head,2);
    insertafteranode(second);

    
    traverseCLL(head);




return 0;    
}