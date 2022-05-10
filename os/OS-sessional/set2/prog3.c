#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    int n = 0, ret, c = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("IN Parent\n\n");

    for (int i = 0; i < n; i++)
    {
        int s;
        if (!fork())
        {
            if (i >= 3)
            {
                char *args[] = {"ls", NULL};
                execvp(args[0], args);
            }
            else
            {
                char *args[] = {"gcc", NULL};
                execvp(args[0], args);
            }
        }
        else
            wait(&s);
        if (s == 0)
            c++;
    }
    printf("OUT Parent\n\n");
    if (c >= n / 2)
        ret = 0;
    else
        ret = 1;
    return ret;
}
