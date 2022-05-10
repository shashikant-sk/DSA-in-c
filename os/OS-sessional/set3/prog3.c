#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    int n = 3, ret, c = 0;
    // printf("Enter n: ");
    // scanf("%d", &n);
    printf("IN Parent\n\n");

    for (int i = 0; i < n; i++)
    {
        int s;
        if (!fork())
        {
            char *args[] = {"ls", NULL};
            execvp(args[0], args);
        }
        else
            wait(&s);
        if (s == 0)
        {
            printf("OUT Parent\n\n");
            return 0;
        }
    }
    printf("OUT Parent\n\n");
    return 1;
}
