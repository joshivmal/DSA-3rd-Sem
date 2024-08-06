#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *pre;
    }s;

    void traverse(s *head){
        s *temp=head;
        while(temp->next!=NULL){
            temp=temp->next;

            printf("%d\n",temp->data);
        }
        
        // while(temp!=first->pre){
        //     printf("%d\n",temp->data);
        //     temp=temp->pre;}
    }
    s *insertfst(s *head,int val){   //insertion at first

    s *newnode ;
    newnode=(s*)malloc(sizeof(s));
    newnode->data=val;
    s *post=head->next;
   newnode->next=head->next;
   head->next=newnode;
   post->pre=newnode;
   newnode->pre=head;

   return head;
   }

   s *insert_at_end(s *head,int val){
    s *newnode,*temp=head ;
    newnode=(s*)malloc(sizeof(s));
    newnode->data=val;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->pre=temp;
    newnode->next=NULL;
    
    return head ;
   }

   s *insert_at_index(s* head,int ind){
      s *newnode,*temp=head ;
    newnode=(s*)malloc(sizeof(s));
    newnode->data=51;
    int i=0;
    while(i<ind){
        temp=temp->next;
        i++;
    }
    s *post=temp->next;
    temp->next=newnode;
    newnode->pre=temp;
    newnode->next=post;
    post->pre=newnode;

    return head ;}

   s *insert_after_a_given_node(s *head,s*node){
    s *newnode,*temp=head ;
    newnode=(s*)malloc(sizeof(s));
    newnode->data=97;
    while(temp!=node){
        temp=temp->next;
    }
    s*post=temp->next;
    if(temp==node){
        temp->next=newnode;
        newnode->next=post;
        post->pre=newnode;
        newnode->pre=temp;
    }
    return head;
   }


    int main(){

    s *head,*first,*second,*third,*fourth;

    head=(s*)malloc(sizeof(s));
    first=(s*)malloc(sizeof(s));
    second=(s*)malloc(sizeof(s));
    third=(s*)malloc(sizeof(s));
    fourth=(s*)malloc(sizeof(s));

    head->next=first;
    first->pre=head;
    first->data=5 ;
    first->next=second;
    first->pre=NULL;

    second->data=6;
    second->next=third;
    second->pre=first;

    third->data=7;
    third->next=fourth;
    third->pre=second;

    fourth->data=8;
    fourth->next=NULL;
    fourth->pre=third;



    traverse(head);
    printf("after updation\n");
    insertfst(head,45);
    insert_at_end(head,47);
    insert_at_index(head,4);
    insert_after_a_given_node(head,first);

    traverse(head);


    return 0;
    }
    
