#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data ;
    struct node *left,*right ;
}s;

s *newnoder(int val){
    s *newnode=(s*)malloc(sizeof(s));
    newnode->data = val ;

    newnode->right=NULL ;
    newnode->left=NULL ;
    return newnode ;
}

// int count_nodes(s*root){
//     static int count = 0 ;
//     while(root!=NULL){
//         count++;
//         count_nodes(root->left) ;
//         count_nodes(root->right) ;
//         printf("no of nodes %d\n",count);

//     }
//     else{
//         return;
//     }
//     }

int count_nodes2(s *root){     //gaurav
   if(root!=NULL){
    int left = count_nodes2(root->left) ;
    int right = count_nodes2(root->right) ;
    int sum = left + right+1 ;
    return sum ;

   }
   
}

int height(s *root){
    if(root ==  NULL){
        return 0 ;  }

    int ans ;
    int left = height(root->left) ;
    int right = height(root->right) ;
    if(left>right){
        ans=left+1;
    }
    else{
        ans = right +1 ;
    }
    return ans ;
    }


    
     



int main(){

    s*a = newnoder(5);  
    s*b=newnoder(3);                
    s*c=newnoder(8);                
    s*d=newnoder(2);               
    s*e=newnoder(4);              
    s*f=newnoder(6);
    s*g=newnoder(10);

    a->left= b ;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    //count_nodes(a);
    //printf("%d",count_nodes2(a));
    printf("%d",height(a));

    return 0;
}