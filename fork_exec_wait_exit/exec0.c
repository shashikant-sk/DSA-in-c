#include<stdio.h>
#include<unistd.h>
int main()
{
    char *args[]={"./exec_target", "First Name", "Last Name", NULL};
    execvp(args[0],args);

    printf("This never prints!");

    return 0;
}
