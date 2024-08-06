#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left,*right;
}s;

void inorder(s *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

s *inorderpredecessor(s *root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right ;
    }
    return root;
}

int inordersuccessor(s *root){
    root=root->right ;
    while(root->left!=NULL){
        root=root->left ;
    }
    return root->data;
}

int isBST(s *root){
    static s *pre=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(pre!=NULL && pre->data >= root->data){
            return 0;
        }
        pre = root;
        return isBST(root->right) ;
    }
    else{
        return 1;
    }
}

s *newnoder(int datar){

    s* newnode=(s*)malloc(sizeof(s));
    newnode->data = datar ;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

s *search(s*root,int key){

    if(root==NULL)
      return NULL ;
    
    else if(root->data==key){
        return root;
    }
    else if(root->right==NULL && root->left==NULL){
        return NULL;
    }

    else{
        if(key < root->data){
            return search(root->left,key);
        }
        else{
            return search(root->right,key);
        } }}

s *iterativesearch(s*root,int key){
    while(root!=NULL){
        if(key==root->data){
            return root;}
        else if(key>root->data){
            root=root->right ;}
        else{
            root=root->left;}}
        return NULL;
    }

s *insertBST(s*root,int value){
    s *new=newnoder(value) ;
    while(root->right!=NULL && root->left!=NULL){
    if(value > root->data){
        return insertBST(root->right,value) ; }
    else{
        return insertBST(root->left,value);}}

    if(value<root->data){
        root->left=new;
        
    }
    else if(value==root->data){
        printf("\nno two values can be same in BST");
        return NULL;
    }
    else{
        root->right=new;
        return NULL;
    }
}


/*s*deletenodeBST(s *root,int key){
    static s *par;
    if(key<root->data){
        par=root;
        return deletenodeBST(root->left,key);}
    else if(key>root->data){
        par=root;
        return deletenodeBST(root->right,key);}
    else{
        if(par->data > key){
            par->left=NULL;}
        else{
        par->right=NULL ;}
        free(root); } 
}  */
    
s *deletenodeinBST(s *root,int key){
    s *ipre ;

    if(root== NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL)
         {
 
            free(root);
            return NULL ; }
           
        
    if(key > root->data){
        root->right=deletenodeinBST(root->right,key); }

    else if(key < root->data){
            root->left= deletenodeinBST(root->left,key);
             }
    else{
                ipre= inorderpredecessor(root);
                root->data = ipre->data ;
                root->left=deletenodeinBST(root->left,ipre->data);
             }
             return root;
             
            
        }

struct node *deleteNode(struct node *root, int value){

    struct node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }

    //searching for the node to be deleted
    if (value < root->data){
        root-> left = deleteNode(root->left,value);
    }
    else if (value > root->data){
        root-> right = deleteNode(root->right,value);
    }
    //deletion strategy when the node is found
    else{
        iPre = inorderpredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
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
    //insertBST(a,7);
    //deletenodeBST(a,3);
    deletenodeinBST(a,3);
    //deletenodeinBST(a,4);
    
    printf("\n");
    inorder(a);

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
    //     2   4 6  10  
          /\      \  
         1         7*/