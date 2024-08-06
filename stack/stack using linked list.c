#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}s;

void traverse(s *top)
{
    if(top!=NULL){
       s *tem=top;
        printf("data of node\n");
        while(tem!=NULL){
            printf("%d\n",tem->data);
            tem=tem->next;
        }}
    else{
        printf("stack is empty");
    }

}

int isempty(s *top){
    if(top==NULL){
        {
            printf("stack is empty");
            return 0;
        }
    return 1;
    }}

int isfull(){
    s *h=(s*)malloc(sizeof(s));

    if(h!=NULL){

      return 1;}
    else{
        printf("overflow");
        return 0;
    }
}
s *push(s *top,int item){
    if(isfull()){    
    s *newnode=(s*)malloc(sizeof(s));
    newnode->data=item;
    newnode->next=top;
    top=newnode;}
    return top;

}

s*pop(s*top){
    if(isempty(top)){
        s *temp=top;
        top=top->next;
        free(temp);
    }
    return top;
}

int peep(s*top){
    int item=top->data;
    return item;
}

int peek(int ind,s*top){

    int i=1;
    s*temp=top;
    while(i<=ind || i!=NULL){
        if(i<ind){
            temp=temp->next;
            i++;
        }
        else{
            int item=temp->data; 
            return item ;
        }

    }



}
s*disposestack(s *top){
    while(top!=NULL){
    s* temp=top;
    top=top->next;
    free(temp);
    }
    return top;

}

int main(){

    s *top=NULL,*temp;
    int i=1,data;
    while(i){

        s *newnode = (s*)malloc(sizeof(s));
        printf("enter the data of the node\n");
        scanf("%d",&data);
        newnode->data=data;
        if(top==NULL){
            top=newnode;
            temp=newnode;}
        else{
            temp->next=newnode;
            newnode->next=NULL;
            temp=newnode;
        }
        printf("press 1=newnode and 0 = stop\n");
        scanf("%d",&i);
        }



        traverse(top);
        //top=push(top,45);
        //top=pop(top);
        //int item=peep(top);
        //printf("last element is %d \n",item);
        //top=disposestack(top);
        int peekitem=peek(3,top);
        printf("index element is %d\n",peekitem);


        traverse(top);


        

        
    return 0;
}
