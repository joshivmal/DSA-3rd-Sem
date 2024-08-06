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
        
        // while(temp!=head->pre){
        //     printf("%d\n",temp->data);
        //     temp=temp->pre;}
    }
    s *deletionfst(s*head){
        s*temp=head->next;
        s*post=temp->next;

        head->next=temp->next;
        post->pre=temp->pre;
        free(temp);
        return head;
        }

    s *deletion_at_end(s*head){
        s*temp=head->next,*prev=head;
        while(temp->next!=NULL){
            temp=temp->next;
            prev=prev->next;
        } 
        prev->next=NULL;
        free(temp);

        return head;
          }

    s *deletion_at_index(s *head,int ind){    //not working for 
        s*temp=head->next;                    // first and last
        int i=0;
        while(i<ind-1){
            temp=temp->next;
            i++;
        }
        s *post=temp->next;
        temp->next=post->next;
        s *mpost=post->next;
        mpost->pre=post->pre;
        free(post);


        return head;


        }

        s *insert_after_a_given_val(s *head, int val){   //not working for 
        s *pre=head,*temp,*post;                         //last node value
        temp=head->next;
        while(temp->data!=val){
            temp=temp->next;
            pre=pre->next;
        }
        post=temp->next;
        pre->next=post;

        post->pre=pre;
        free(temp);

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
    head->pre=NULL;
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
    //deletionfst(head);
    //deletion_at_end(head);
    //head=deletion_at_index(head,2);  
    head=insert_after_a_given_val(head,8);

    traverse(head);


    return 0;
    }
    
