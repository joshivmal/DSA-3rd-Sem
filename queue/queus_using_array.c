#include <stdio.h>
int front = -1, rear = -1, n;


void traverse(int queue[]){
    for(int i=front;i<=rear;i++){
        printf("%d\n",queue[i]);
    }

}

int isempty(int queue[])
{
    if (front == -1)
    {
        printf("underflow");
        return 0;
    }
    return 1;
}
int isfull(int queue[])
{
    if (front == 0 && rear == n - 1)
    {
        printf("overflow");
        return 0;
    }
    return 1;
}
int enqueue(int queue[], int item)
{
    if (isfull(queue))
    {
        if (front == -1 && rear == -1)
        {
            rear++;
            front++;
            queue[rear] = item;
        }
        else
        {
            rear++;
            queue[rear] = item;
        }
        return rear;
    }
}
int dequeue(int queue[])
{
    if (isempty(queue))
    {
        printf("popped element is %d\n", queue[front]);
        if(front==rear){
            front=rear=-1;
        }
        else{
        front++ ;}
        return front ;
    }
}

int main()
{

    printf("enter the size of queue ");
    scanf("%d", &n);
    int queue[n];

    rear=enqueue(queue,5);
    rear=enqueue(queue,6);
    rear=enqueue(queue,7);
    rear=enqueue(queue,8);
    rear=enqueue(queue,9);
    rear=enqueue(queue,10);
    rear=enqueue(queue,11);
    front=dequeue(queue);
    traverse(queue);

    return 0;
}