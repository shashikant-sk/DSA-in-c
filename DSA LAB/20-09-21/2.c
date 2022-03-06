// Q2) Write a menu driven program to implement queue operations such as Enqueue, Dequeue, Peek, 
// Display of elements, IsEmpty, IsFull 
// using static array.
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, size;
    int capacity;
    int* array;
};
 
struct Queue* makeQueue(int capacity){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
 
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}
 
int isFull(struct Queue* queue){
    return (queue->size == queue->capacity);
}
 
int isEmpty(struct Queue* queue){
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item){
    if (isFull(queue))return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

int dequeue(struct Queue* queue){
    if (!isEmpty(queue)){
        int item = queue->array[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size = queue->size - 1;
        return item;
    }
}

int front(struct Queue* queue){
    if (!isEmpty(queue))
        return queue->array[queue->front];
}
 
int rear(struct Queue* queue){
    if (!isEmpty(queue))
        return queue->array[queue->rear];
}

int display(struct Queue* queue){
    printf("Queue -> ");
    for(int i=queue->front;i<=queue->rear;i++){
        printf("%d ",queue->array[i]);
    }
    printf("\n");
}
 
int main(){

    struct Queue* queue = makeQueue(1000);
 
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
 
    printf("%d dequeued from queue\n\n",dequeue(queue));
    
    display(queue);
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));
 
    return 0;
}