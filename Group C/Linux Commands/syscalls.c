/* PS - Process Status; ps command is used to list the currently running processes and their PIDs along with some other information depends on different options. 
PS shows - PID, TTY, TIME, CMD 
*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

char* args1[] = {"ps",NULL};
char* args2[] = {"ls",NULL};
char* args3[] = {"join","file1","file2",NULL};
int choice, pid, id, status;

int main() {
	printf("\n1.ps\n2.fork\n3.join\n4.exec\n5.wait\n6.exit");
	scanf("%d", &choice);
	switch(choice) {
	case 1:
		execvp(args1[0],args1);
		break;
	case 2:
		pid = fork();
		if(pid == 0) {
			sleep(5);
			printf("Child process %d\n",getpid());
			sleep(5);
			printf("Parent process %d\n",getppid());
		}
		else if(pid > 0) {
			sleep(5);
			printf("Child process %d\n",getpid());
			sleep(5);
			printf("Parent process %d\n",getppid());
		}
		break;
	case 3:
		execvp(args3[0],args3);
		break;
	case 4:
		execvp(args2[0],args2);
		break;
	case 5:
		pid = fork();
		if(pid == 0) {
			printf("Child process %d\n",getpid());
			printf("Parent process %d\n",getppid());
			id = wait(&status);
			printf("Process terminated");
		}
		else if(pid > 0) {
			printf("Child process %d\n",getpid());
			printf("Parent process %d\n",getppid());
			id = wait(&status);
			printf("Process terminated");
		}
		break;
	case 6:
		break;
	}
}
