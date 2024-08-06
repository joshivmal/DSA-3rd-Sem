// reverse the array using recursion
// #include<iostream>
#include<bits/stdc++.h>
using namespace std ;


void printArray(int arr[],int n){

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" " ;
    }
    cout<<endl;
}

// reverse using two variables

// void reverseArray(int l,int r,int arr[]){

//     if(l>=r) return  ; 

//     int temp = arr[l] ;
//     arr[l] = arr[r] ;
//     arr[r] = temp ;

//     reverseArray(l+1,r-1,arr) ;

// }

// reverse using single variable

void reverseArraySingle(int i, int n,int arr[])
{
    if(i>=n/2)  return  ;

    swap(arr[i],arr[n-i-1]) ;
    reverseArraySingle(i+1,n,arr) ;
}

bool checkPalindrome(int i,string str){
   
    int n = str.length() ;

     if(i>=n/2)    return true ;  
    if(str[i]!=str[n-i-1])    return false ;

    return checkPalindrome(i+1,str) ;


}

int main(){

    // int arr[] ={1,2,3,4,5,6,7} ;
    // int n = sizeof(arr)/sizeof(arr[0]);
    // printArray(arr,n) ;
    // reverseArray(0,n-1,arr) ;
    // reverseArraySingle(0,n,arr) ;
    // printArray(arr,n) ;

    string str = "namnan" ;
    //  if(checkPalindrome(0,str)) cout<<"True"<<endl ;
    //  else cout<<"False" ;
     cout<<checkPalindrome(0,str)<<endl  ;
    return 0;

}