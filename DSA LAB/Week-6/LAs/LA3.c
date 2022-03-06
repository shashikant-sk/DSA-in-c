// Write a menu driven program to implement circular queue operations such as Enqueue, Dequeue, Peek, Display of elements,
// IsEmpty, IsFull using static array.
#include <stdio.h>

struct Cqueue
{
    int front, rear, size;
    int queue[100];
};

int isEmpty(struct Cqueue q)
{
    return (q.front == -1);
}

int isFull(struct Cqueue q)
{
    return ((q.front == 0 && q.rear == q.size - 1) || (q.rear == (q.front - 1) % (q.size - 1)));
}

void peek(struct Cqueue q)
{
    if (!isEmpty(q))
        printf("\nPeek element = %d\n",q.queue[q.front]);
    else
        printf("\nQueue is Empty\n");
}

void enQueue(struct Cqueue *q, int value)
{
    if (isFull(*q))
    {
        printf("\nQueue is Full\n");
        return;
    }
    else if (q->front == -1)
    {
        q->front = q->rear = 0;
        q->queue[q->rear] = value;
    }
    else if (q->rear == q->size - 1 && q->front != 0)
    {
        q->rear = 0;
        q->queue[q->rear] = value;
    }
    else
    {
        q->rear++;
        q->queue[q->rear] = value;
    }
}

void deQueue(struct Cqueue *q)
{
    if (!isEmpty(*q))
    {
        int data = q->queue[q->front];
        q->queue[q->front] = -1;
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else if (q->front == q->size - 1)
            q->front = 0;
        else
            q->front++;
        printf("\nDequeued element = %d\n",data);
    }
    else
        printf("\nQueue is Empty\n");
}

void displayQueue(struct Cqueue q)
{
    if (!isEmpty(q))
    {
        printf("\nElements in Circular Queue are: ");
        if (q.rear >= q.front)
        {
            for (int i = q.front; i <= q.rear; i++)
                printf("%d ", q.queue[i]);
        }
        else
        {
            for (int i = q.front; i < q.size; i++)
                printf("%d ", q.queue[i]);

            for (int i = 0; i <= q.rear; i++)
                printf("%d ", q.queue[i]);
        }
    }
    else
        printf("\nQueue is Empty\n");
}

int main()
{
    struct Cqueue q;
    q.front = q.rear = -1;
    q.size = 0;
    int choice, item;
    printf("Enter max size of circular queue: ");
    scanf("%d",&q.size);
    while (1)
    {
        printf("\n--------MENU FOR QUEUE--------\n"
               "1.Enqueue\n"
               "2.Dequeue\n"
               "3.Display Queue\n"
               "4.Peek at front\n"
               "5.Check if queue is empty\n"
               "6.Check if queue is full\n"
               "7.Quit\n"
               "Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Input the element for insertion in queue : ");
            scanf("%d", &item);
            enQueue(&q,item);
            break;
        case 2:
            deQueue(&q);
            break;
        case 3:
            displayQueue(q);
            break;
        case 4:
            peek(q);
            break;
        case 5:
            isEmpty(q)?printf("\nQueue is empty!\n"):printf("\nQueue is not empty!\n");
            break;
        case 6:
            isFull(q)?printf("\nQueue is full!\n"):printf("\nQueue is not full!\n");
            break;
        case 7:
            return 0;
            break;
        default:
            printf("\nWrong choice\n");
        }
    }
    return 0;
}
