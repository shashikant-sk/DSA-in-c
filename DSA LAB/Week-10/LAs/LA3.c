// WAP to create a directed graph using adjacency matrix method.
#include <stdio.h>

int vertices = 0, edges = 0;

void addEdge(int Adj[][vertices], int m, int n)
{
    Adj[m][n] = 1;
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
    printf("Enter number of vertices of directed graph: ");
    scanf("%d", &vertices);
    int Adj[vertices][vertices];
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            Adj[i][j] = 0;
    while (choice != 0)
    {
        int m, n;
        printf("Enter 2 vertices to form edge: ");
        scanf("%d %d", &m, &n);
        addEdge(Adj, m, n);
        edges++;
        printf("Enter 1 to continue or 0 to exit: ");
        scanf("%d", &choice);
    }
    printAdjMatrix(Adj);
    return 0;
}
