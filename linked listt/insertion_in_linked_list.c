#include<stdio.h>
#include<stdlib.h>
//insert at first  complexity O(1)
// insert at index O(n)
//insert at the end  O(n)
// insert after a given node O(1)
typedef struct node{
    int data;
    struct node *next;
}s;

void traverse(s *head){
    s *ptr =head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }}
    
s *insertfst(s *head,int data){   //insertion at first

    s *temp=head,*new;
    new=(s*)malloc(sizeof(s));
    new->data=data;
    new->next=head;
    head=new;
    
    return head;

    }
s *insertatindex(s *head,int data,int ind){   //insert at a index

    s *newnode=(s*)malloc(sizeof(s));
    s *p=head;
    int i=1;
    while(i<ind-1){
        p=p->next;
        i++;  }
    newnode->data=data;
    newnode->next=p->next;
    p->next=newnode;
    
    return head;}
s *InsertAtEnd(s *head,int data){     //insert at the end
    s *newnode=(s*)malloc(sizeof(s));
    newnode->data=data;
    s *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=newnode;
    newnode->next=NULL;

    return head;

}

s *InsertAfterNode(s *givennode,int data ){      //insert after a given node
    s *newnode=(s*)malloc(sizeof(s));
    newnode->data=data;
    newnode->next=givennode->next;
    givennode->next=newnode;
    
    
    return 0;

    
}

int main(){
    
    s *head =NULL,*newnode,*ptr;
    int i=1 ;
    while(i){
        newnode = (s*)malloc(sizeof(s));
        printf("enter the data of the node ");
        scanf("%d",&newnode->data);
        newnode->next = NULL ;
        if(head==NULL){
            head = newnode ;
            ptr = newnode ;  }
        else{
            ptr->next=newnode;
            ptr = newnode ;}
        printf("enter 1 for continue and 0 for stop");
        scanf("%d",&i);
        }

    // printf("node before changes\n");
    // traverse(head);
    // printf("data of new node");
    // scanf("%d",&data);

    //head=insertfst(head,data);
    //head=insertatindex(head,data,3);
    //InsertAtEnd(second,data);
    //head=InsertAfterNode(third,data);
    
    traverse(head);
   
    

    return 0;


}