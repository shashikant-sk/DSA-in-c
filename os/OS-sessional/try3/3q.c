
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
	int pid, pid1, pid2;
	pid = fork();
	if (pid == 0) {
		sleep(3);
		printf("child[1] --> pid = %d and ppid = %d\n",
			getpid(), getppid());
	}

	else {
		pid1 = fork();
		if (pid1 == 0) {
			sleep(2);
			printf("child[2] --> pid = %d and ppid = %d\n",
				getpid(), getppid());
		}
		else {
			pid2 = fork();
			if (pid2 == 0) {
			
				printf("child[3] --> pid = %d and ppid = %d\n",
					getpid(), getppid());
			}
			else {
				
				sleep(3);
				printf("parent --> pid = %d\n", getpid());
			}
               	}
	}
	return 0;
}
