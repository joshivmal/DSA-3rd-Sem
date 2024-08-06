//deletion
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int data;
struct node *next;
}s;

void traverse(s *head){
     s *temp=head;
     while(temp!=NULL){
     printf("%d\n",temp->data);
     temp=temp->next;}
     }

s *DeleteAtFirst(s *head){           //deleting first node /complexity=O(1)
  s *temp=head;
  head=head->next;
  free(temp);
  return head;
  }
  
 s *DeleteAtIndex(s *head,int ind){   //delete the node with index/complexity=O(n)
   s *temp=head;
   int i=1;
   while(i<ind-1){
   temp=temp->next;
   i++;}
   s *indnum=temp->next;
   temp->next=indnum->next;
   free(indnum);
   
   return head;
   }

s *DeleteTheEnd(s *head){  //deletion at End   /complexity=O(1)
    s *temp=head,*pre;
    while(temp->next!=NULL){
         pre=temp;
        temp=temp->next;
    }
    pre->next=NULL;
    free(temp);
    return head;
}

s *DeletionofGivenNode(s *head,s*node){     // deletion of a node complexity=O(n)
    // s *temp=head,*prev;
    // while(temp->next!=NULL){
    //   prev=temp;
    //   if(temp==node){
    //     prev->next=temp->next;
    //     free(temp);
    //     break;
    //   }
    //   else{
    //   temp=temp->next;
    //   } 
    // return head;}
    s *temp=head;
    while(temp->next!=node){
      continue;
    }
    temp->next=node->next;
    free(node);
    return head;


}

s *Delete_the_node_with_given_value(s *head,int val){    //complexity O(n)  //not working for the first node data
    s *temp=head; 
    s *post=head->next;
    while(post->data!=val && post->next!=NULL){
        post=post->next;
        temp=temp->next;}
        
        if(post->data==val){
            temp->next=post->next;
            free(post);
        }
        else{
            printf("data is not present in the list\n");}
        return head;

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
fourth->next=NULL;
traverse(head);
printf("after updation\n");
//head=DeleteAtFirst(head);
//head=DeleteAtIndex(head,2);
//head=DeleteTheEnd(head);
//head=DeletionofGivenNode(head,second);   not working for the third 

head=Delete_the_node_with_given_value(head,5);
traverse(head);
return 0;
}