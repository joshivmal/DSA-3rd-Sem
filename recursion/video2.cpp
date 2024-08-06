#include<iostream>
using namespace std ;

int count = 0;
void printName(int i, int n){
    
    if(i > n) return ;
    cout<<"Vimal"<<endl ;
    printName(i+1,n) ;
}

void printTillN(int i,int n){

    if(i>n) return ;
    cout<<i<<endl ;
    printTillN(i+1,n) ;
}

void printFromNto1(int n)
{
    if(n==0) return ;
    cout<<n<<" ";
    printFromNto1(--n);
}
void print1toNusingBT(int i,int n){

    if(i==0) return ;
    print1toNusingBT(i-1,n) ;
    cout<<i<<" " ;

}
void printNto1usingBT(int i,int n){

    if(i>n) return ;

    printNto1usingBT(i+1,n) ;

    cout<<i<<" ";

}


int main()
{
    int n = 5 ;
    // printName(1,n) ;
    // printTillN(1,n) ;
    //printFromNto1(5) ;
    // print1toNusingBT(n,n);
    printNto1usingBT(1,n) ;

}