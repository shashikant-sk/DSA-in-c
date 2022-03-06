// Write a menu driven program to implement Deques (both Input-restricted and Output-restricted) operations
// such as Enqueue, Dequeue, Peek, Display of elements, IsEmpty, IsFull using static array.
#include <stdio.h>

struct Dequeue
{
    int front, rear, size;
    int dequeue[100];
};

int isFull(struct Dequeue q)
{
    return ((q.front == 0 && q.rear == q.size - 1) || q.front == q.rear + 1);
}

int isEmpty(struct Dequeue q)
{
    return (q.front == -1);
}

void insertfront(struct Dequeue *q, int key)
{
    if (isFull(*q))
    {
        printf("\nDeQueue Full\n");
        return;
    }
    if (q->front == -1)
        q->front = 0, q->rear = 0;
    else if (q->front == 0)
        q->front = q->size - 1;
    else
        (q->front)--;
    q->dequeue[q->front] = key;
}

void insertrear(struct Dequeue *q, int key)
{
    if (isFull(*q))
    {
        printf("\nDeQueue Full\n");
        return;
    }
    if (q->front == -1)
        q->front = q->rear = 0;
    else if (q->rear == q->size - 1)
        q->rear = 0;
    else
        (q->rear)++;
    q->dequeue[q->rear] = key;
}

void deletefront(struct Dequeue *q)
{
    if (isEmpty(*q))
    {
        printf("\nDeQueue Empty\n");
        return;
    }
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else if (q->front == q->size - 1)
        q->front = 0;
    else
        (q->front)++;
}

void deleterear(struct Dequeue *q)
{
    if (isEmpty(*q))
    {
        printf("\nDeQueue Empty\n");
        return;
    }
    if (q->front == q->rear)
        q->front = q->rear = -1;
    else if (q->rear == 0)
        q->rear = q->size - 1;
    else
        (q->rear)--;
}

void getFront(struct Dequeue q)
{
    if (!isEmpty(q))
        printf("\nPeek front = %d\n", q.dequeue[q.front]);
    else
        printf("\nDeQueue Empty\n");
}

void getRear(struct Dequeue q)
{
    if (isEmpty(q) || q.rear < 0)
        printf("\nDeQueue Empty\n");
    else
        printf("\nPeek rear = %d\n", q.dequeue[q.rear]);
}

void displayQueue(struct Dequeue q)
{
    if (!isEmpty(q))
    {
        printf("\nElements in DeQueue are: ");
        if (q.rear >= q.front)
            for (int i = q.front; i <= q.rear; i++)
                printf("%d ", q.dequeue[i]);
        else
        {
            for (int i = q.front; i < q.size; i++)
                printf("%d ", q.dequeue[i]);

            for (int i = 0; i <= q.rear; i++)
                printf("%d ", q.dequeue[i]);
        }
    }
    else
        printf("\nDequeue is Empty\n");
}

int main()
{
    struct Dequeue q;
    q.front = q.rear = -1;
    q.size = 0;
    int choice, item;
    printf("Enter max size of dequeue: ");
    scanf("%d", &q.size);
    while (1)
    {
        printf("\n--------MENU FOR QUEUE--------\n"
               "1.Insert at front\n"
               "2.Insert at rear\n"
               "3.Delete at front\n"
               "4.Delete at rear\n"
               "5.Display Queue\n"
               "6.Peek at front\n"
               "7.Peek at rear\n"
               "8.Check if queue is empty\n"
               "9.Check if queue is full\n"
               "10.Quit\n"
               "Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Input the element to insert at front of dequeue : ");
            scanf("%d", &item);
            insertfront(&q, item);
            break;
        case 2:
            printf("Input the element to insert at rear of dequeue : ");
            scanf("%d", &item);
            insertrear(&q, item);
            break;
        case 3:
            deletefront(&q);
            break;
        case 4:
            deleterear(&q);
            break;
        case 5:
            displayQueue(q);
            break;
        case 6:
            getFront(q);
            break;
        case 7:
            getRear(q);
            break;
        case 8:
            isEmpty(q) ? printf("\nQueue is empty!\n") : printf("\nQueue is not empty!\n");
            break;
        case 9:
            isFull(q) ? printf("\nQueue is full!\n") : printf("\nQueue is not full!\n");
            break;
        case 10:
            return 0;
            break;
        default:
            printf("\nWrong choice\n");
        }
    }
    return 0;
}
