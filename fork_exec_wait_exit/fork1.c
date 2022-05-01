#include <stdio.h>
#include <unistd.h>
int main()
{   // 0
    fork();  // 1 - 11, 12 - 111
    fork();  // 2 - 21
    fork();  // 3
    printf("hello\n");
    return 0;
}