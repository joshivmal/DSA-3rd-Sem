//bubblesort time complexity =O(n^2)= total comparison=(n-1)/2
//it is a stable algorithum= if two numbers are 
//same then first no. will come first
//by default it is not adaptable algorithum but we can 
//make this adaptable= in sorting array it will take less time

#include<stdio.h>

void print(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    printf("\n");
}

void bubblesort(int a[],int n){   //ascending order
    int temp;
    for(int i=0;i<n-1;i++){  //for number of passes
        for(int j=0;j<n-i-1;j++){ //for number of comparison

            if(a[j+1]<a[j]){
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
}
void bubblesortadaptable(int a[],int n){
    int temp,issorted=0;
    for(int i=0;i<n-1;i++){
        printf("no. of passes runned %d\n",i+1);
        issorted=1;
        for(int j=0;j<n-i-1;j++){
             if(a[j+1]<a[j]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                issorted=0;
             }}
         if(issorted){
             return;
        }
    }
}
//insertion sort
// it is adaptable and stable too (best time complexity=O(n))
//total comparison =1,2....n-1=n(n-1)/2=O(n^2)

void insertion_sort(int a[],int n){
    
    for(int i=1;i<n;i++)
    {  //no. of passes 
        int key=a[i];
        int j=i-1;
    while(a[j]>key && j>=0){  //for comparison
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=key;
    }}

   // selection sort time complexity is O(n^2)=n(n-1)/2
   //it is not adapatable but is stable 


void selectionsort(int *a,int n){
    for(int i=0;i<n-1;i++)
    { //no. of passes
        int minid=i;
        for(int j=i+1;j<n;j++){ // no. of swaps
            if(a[j]<a[minid]){
                minid=j;
            }}
        if(minid!=i){
                int temp=a[minid];
                a[minid]=a[i];
                a[i]=temp ;
            }
    }}


int main(){

   int arr[]={1,7,2,3,5,2,9};
   int arr2[]={1,2,3,4,8,6,7};
   //bubblesort(arr,7);
   print(arr,7);
   //bubblesortadaptable(arr2,7);
   //insertion_sort(arr,7) ;
   selectionsort(arr,7);
   print(arr,7);

    return 0;
}