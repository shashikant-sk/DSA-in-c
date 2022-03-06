// Modify the above program to include a menu driven program and add options for the depth-first traversal and breadth-first traversal.
#include <stdio.h>
#include <stdlib.h>

int vertices = 0, edges = 0;
struct queue
{
    int front, rear;
    int data[100];
};

void DFT(int start, int visited[], int Adj[][vertices])
{
    printf("%d ", start);
    visited[start] = 1;
    for (int i = 0; i < vertices; i++)
        if (Adj[start][i] == 1 && (!visited[i]))
            DFT(i, visited, Adj);
}

void _DFT(int start, int Adj[][vertices])
{
    int visited[vertices];
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;
    DFT(start, visited, Adj);
}

int Isempty(struct queue q)
{
    if (q.front == -1 || q.front > q.rear)
        return 1;
    return 0;
}

void BFT(int start, int nodes, int Adj[][vertices])
{
    int *visited = (int *)malloc(sizeof(int) * nodes);
    for (int i = 0; i < nodes; i++)
        visited[i] = 0;
    struct queue q;
    q.front = q.rear = 0;
    q.data[q.rear] = start;

    visited[start] = 1;

    int vis;
    while (!Isempty(q))
    {
        vis = q.data[q.front];
        printf("%d ", vis);
        q.front++;
        for (int i = 0; i < nodes; i++)
        {
            if (Adj[vis][i] == 1 && (!visited[i]))
            {
                q.data[++q.rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void addEdge(int Adj[][vertices], int m, int n)
{
    Adj[m][n] = Adj[n][m] = 1;
}

void printAdjMatrix(int Adj[][vertices])
{
    printf("\nThe Adjacency matrix: \n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
            printf("%d ", Adj[i][j]);
        printf("\n");
    }
}

int main()
{
    int choice = 1;
    printf("Enter number of vertices of undirected graph: ");
    scanf("%d", &vertices);
    int Adj[vertices][vertices];
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            Adj[i][j] = 0;
    while (choice)
    {
        printf("\n------------GRAPH MENU------------\n"
               "0)To exit\n"
               "1)Add a new edge\n"
               "2)To print Adjajency matrix\n"
               "3)Depth First Traversal\n"
               "4)Breadth First Traversal\n"
               "Enter a choice!\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            return 0;
            break;
        case 1:
        {
            int m, n;
            printf("Enter 2 vertices to form edge: ");
            scanf("%d %d", &m, &n);
            addEdge(Adj, m, n);
            edges++;
        }
        break;
        case 2:
            printAdjMatrix(Adj);
            break;
        case 3:
        {
            int k;
            printf("Enter node to start DFT: ");
            scanf("%d", &k);
            _DFT(k, Adj);
        }
        break;
        case 4:
        {
            int k;
            printf("Enter node to start BFT: ");
            scanf("%d", &k);
            BFT(k, vertices, Adj);
        }
        break;
        default:
            printf("Enter a valid choice!\n");
            break;
        }
    }
    return 0;
}
