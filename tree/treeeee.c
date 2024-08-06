#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *right ,*left;
}s;

void preorder(s *root){

    if(root==NULL){
        return ;}
    
    else{
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }}

void insert(s *root,int key){

    s*newnode=(s*)malloc(sizeof(s));
        newnode->right==NULL;
        newnode->left==NULL;
        newnode->data=key;
        
    s *temp=root,*pre;
    if(temp==NULL){
        temp=newnode;
        return ;
    }
    else{
            
        while(temp!=NULL){
            pre=temp;
        if(temp->data=key){
            printf("this data is already exist in BST\n");
            return ;
        }
        else if(key > temp->data)
                temp=temp->right ;
        
        else
            temp=temp->left ;
        }
            }
    if(key > pre->data)
            pre->right = newnode;
    else
        pre->left = newnode;
        
}




int main(){
    
    s*root=(s*)malloc(sizeof(s));
    root->data=9;
    // s *newnode1=(s*)malloc(sizeof(s));
    // s *newnode2=(s*)malloc(sizeof(s));

    // root->data=8;
    // root->right=newnode1;
    // root->left=newnode2;

    // newnode1->data=9;
    // newnode1->right=NULL;
    // newnode1->left=NULL;
    // newnode2->data=5;
    // newnode2->right=NULL;
    // newnode2->left=NULL;



     
    

    insert(root,8);
    insert(root,3);
    insert(root,10);
    insert(root,1);
    insert(root,6);
    insert(root,14);
    insert(root,4);
    insert(root,7);
    insert(root,14);

    preorder(root);





    return 0;
}