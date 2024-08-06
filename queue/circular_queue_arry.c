#include<stdio.h>

int front=-1,rear=-1,n;

int isEmpty(){
    if(front==-1){
        printf("underflow");
        return 0;
    }
    return 1;
    }
int isFull(){
    if(front==0&&rear==n-1){
        printf("overflow");
        return 0;
    }
    return 1;
}

int enqueue(int queue[],int item){
    if(isFull()){
        if(rear==n-1){
            rear=0;
        }
        else if(front==-1)
        {
            front=rear=0;}

        else{
            rear=rear+1;
        }
        queue[rear]=item;
}
    
    return rear;

}
int dequeue(int queue[]){
    if(isEmpty()){
        printf("popped item is %d\n",queue[front]);
        if(front==rear){
            front=rear=-1;
        }
        else if(front==n-1){
            front=0;

        }
        else{
            front=front+1;
        }
    }
     return front;

}


int traverse(int queue[]){
    printf("elements are\n");
    for(int i=front;i<=rear;i++){
        printf("%d\n",queue[i]);
    }
}

int main(){
    printf("enter the number of elements of an array ");
    scanf("%d",&n);
    int queue[n];
    rear=enqueue(queue,5);
    rear=enqueue(queue,6);
    rear=enqueue(queue,7);
    rear=enqueue(queue,8);
    rear=enqueue(queue,9);
    rear=enqueue(queue,10);
    traverse(queue);
    front=dequeue(queue);
    front=dequeue(queue);
    traverse(queue);
    rear=enqueue(queue,15);
    rear=enqueue(queue,20);
    traverse(queue);










    return 0;

}