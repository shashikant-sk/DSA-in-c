#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid_child_0 = 0;
    pid_t pid_child_1 = 0;
    pid_t wait_child_first = 0;
    pid_t wait_child_second = 0;
    int status_child_first, status_child_second;

    pid_child_0 = fork();
    if (pid_child_0 == 0) {
        printf("I am child 0.\n");
        char *args[]={"./exec_target", "First", "Middle", "Last", NULL};
        execvp(args[0],args);
        printf("This never prints!");
    }
    if (pid_child_0 < 0) {
        perror("In fork() of the first child");
    }

    pid_child_1 = fork();
    if (pid_child_1 == 0) {
        printf("I am child 1.\n");
        char *args[]={"./exec_target", "First", "Last", NULL};
        execvp(args[0],args);
        printf("This never prints!");
    }
    if (pid_child_1 < 0) {
        perror("In fork() of the second child");
    }

    wait_child_first = wait(&status_child_first);
    if (wait_child_first == pid_child_0)
        printf("child 0 terminated with status of %d\n", WEXITSTATUS(status_child_first));
    else
        printf("child 1 terminated with status of %d\n", WEXITSTATUS(status_child_first));

    wait_child_second = wait(&status_child_second);
    if (wait_child_second == pid_child_0)
        printf("child 0 terminated with status of %d\n", WEXITSTATUS(status_child_second));
    else
        printf("child 1 terminated with status of %d\n", WEXITSTATUS(status_child_second));

    exit(0);
}