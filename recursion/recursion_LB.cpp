//recursion
#include<iostream>
using namespace std;

// void print(int n){
//     if(n==0)
//     return ;
//     else{
//     printf("hello\n");
//     print(n-1);}
// }

// int fact(int n){
    
//     //base condition
//     if(n==1)
//         return 1 ;
//     //subproblem or recursive call
//     return n*fact(n-1);

//     //final answer [ye bs 12 tak k liye kam krega]

//     //homework -> how to find factorial of large numbers
    
//     }

// int fifo(int n){
//     if(n==0 || n==1)
//        return n;
    
//     else{
//         return fifo(n-1) + fifo(n-2);
//         printf("%d",fifo(n-1) + fifo(n-2));
    
//     }
// }  
    
    



// /*void sumo(int n){
//     static  int sumo=0;
//     if(n==0){
//         printf("sumo =  %d",sumo);
//         return;
//     }
//     else{
//         sumo+=n;
//         sumo(n-1);
//     }
// }*/

// void countinforward(int n){
//     if(n==0)
//        return ;
//     else{
//         countinforward(n-1);
//         printf("%d ",n);
//     }

// }

// void countinreverse(int n){
//     if(n==0)
//        return ;
//     else{
//         printf("%d ",n);
//         countinreverse(n-1);
//     }}

void printstr(int n,string str[]){
    if(n==0)
       return ;
    printstr(n/10,str) ;

    int m=n%10 ;
    cout<<str[m]<<" ";
    
}

int expo(int n,int p){  //TC log n  //SC n
    //static int i=0;
    if(p==0){
        return 1;
    }
    else{

        return n*expo(n,p-1);
    }}

int fastExpo(int n,int p){
    if(p==0){
        return 1;}
        int halfAns=fastExpo(n,p/2) ;

        if(n&1){   //odd conditon 
            return n*halfAns*halfAns ;}
        else{      //even conditon
            return halfAns*halfAns ;
        }
    
    
}


//}
    // if(p==0){
    //     return 1;
    // }
    // else{
    // p++;
    // printf("%d\n",p);
    // return 1/n*expo(n,p);}}


int sorted(int a[],int n){
    if(n==0){
        return 1;
    }
    if(a[n]<a[n-1]){
        return 0;}
    else{
        sorted(a,n-1);
    }
    
}
    




int main(){
    int n,p;
    string str[10]={"zero","first","second","third","four","five","six","seven","eight","nine"};
    int b[5]={1,2,3,4,5};

    // printf("enter the number ");
    // scanf("%d",&n);
    //fact(n);
    //sumo(n);
    //countinforward(n);
    //countinreverse(n);
    // printf("%d ",fact(n));
    //printf("%d",fifo(n));
    //printstr(n,str);
    // cout<<"enter the power ";
    // cin>>p;
    //cout<<expo(n,p)<<endl;
    //cout<<fastExpo(n,p)<<endl;
    if(sorted(b,5)){
        printf("sorted");
    }
    else{
        printf("not sorted");
    }



    return 0;
}