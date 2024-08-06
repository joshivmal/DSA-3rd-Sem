#include<iostream>
using namespace std ;

void sumTillN(int n,int sum){
    if(n<1) {
    cout<<sum<<endl;
    return ;}

    sumTillN(n-1,sum+n);
}

int sumTillNa(int n,int sum){
    if(n<1) {
    return sum;}

    sumTillNa(n-1,sum+n);
    cout<<sum<<" ";
}

int sumTillNnn(int n){
    if(n<1) return 0 ;
    return n+sumTillNnn(n-1) ;
}

int factofN(int n){
    if(n<2) return 1 ;

    return n*factofN(n-1) ;

}

int main(){

    int n = 5 ;
    int sum=0;
    // sumTillN(n,sum) ;             // Parameterized recursin
    // cout<<"ans = "<<sumTillNa(n,0)<<endl ; //error     
    // cout<<"functional reursion -> "<<sumTillNnn(n)<<endl ;

    cout<<factofN(n)<<endl ;
    return 0 ;
}