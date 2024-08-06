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

s*inorderpredecessor(s*root){
    root=root->left ;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}

s*inordersuccessor(s *root){
    root=root->right ;
    while(root->left!=NULL){
        root= root->left ;
    }
    return root;
}


s *searchinBST(s *root,int val){
    if(root->data!=val ){
        if(root->data < val){
            searchinBST(root->right,val);
        }
        else {
            searchinBST(root->left,val);
        }}
    else if (root->data==val){
        printf("present");
        return root ; 
    }
    else{
    printf("value is not present in  BST\n");
    }
    
}


s *inorder(s *root){
    if(root!=NULL){
        inorder(root->left) ;
        printf("%d ",root->data);
        inorder(root->right);
    }

    }

s *preorder(s *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }

}

s*postorder(s*root){
    if(root!=NULL){
        preorder(root->left);
        preorder(root->right);
        printf("%d ",root->data);                     
    }

}

s*insertion(s*root,int key){
    if(root->right!=NULL && root->left!=NULL){
        if(root->data < key){
            insertion(root->right,key) ;
        }
        else if(root->data > key){
            insertion(root->left,key) ;
        }
        else{
            printf("no two values are same in BST\n");}
    }
    else{
        
        s*newnode=newnoder(key) ;
        if(root->data < key){
            root->right = newnode ;}
        else{
            root->left = newnode ;
            
        }
    }
}

s*iterativesearch(s *root,int key){
    while(root!=NULL){
        if(root->data > key){
            root= root->left ;  }
        else{
            root= root->right ;
        }
    }
     if (root->data == key){
        printf("present");
        return root ; 
    }
    else{
    printf("value is not present in  BST\n");
    }

}

s *deletion(s *root,int key){
    if(root->right ==NULL && root->left== NULL){
        
        free(root) ;
        return NULL ;
 
    }
    else if(root->data > key){
       root->left = deletion(root->left,key) ;
    }
    else if(root->data < key){
        root->right = deletion(root->right,key) ;
    }
    else{
        
        s *temp = inorderpredecessor(root);
        root->data = temp->data ;
        deletion(root,root->left) ;
}
return root;}

s *checkBST(s *root){
    static s *pre= NULL ;
    if(root!=NULL){
        if(!checkBST(root->left)){
        return 0;}

        else if(pre!=NULL && pre->data>root->data){
        return 0;}
        pre=root;
        return checkBST(root->right) ;}
    else{
        return 1 ;
    }
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

    inorder(a);
    printf("\n");
    //insertion(a,9);
    //searchinBST(a,2);
    //iterativesearch(a,10);
    // if(checkBST(a)){
    //     printf(" it is a BST");
    // }
    deletion(a,8);
    inorder(a);
    //deletenodeBST(a,3);
    //deletenodeinBST(a,3);
    //deletenodeinBST(a,4);
    
    //printf("\n");
    //inorder(a);

    //printf("\n%d",isBST(a)) ;
    // s*w=search(a,15);
    // s*w=iterativesearch(a,2);
    // if(w==NULL){
    //     printf("\nelement is not present the BST"); }
    // else{
    // printf("\n%d",w->data);}
    return 0;

}

         /*     5
           // /  \
          // 3    8
         // / \  / \
           2   4 6  10   */
       