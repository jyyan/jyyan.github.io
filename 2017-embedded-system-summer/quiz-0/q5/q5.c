#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int pid = 0;
  for (int i = 0; i < 3; i++) {

    pid = fork();
    if (pid == 0) {
      printf("%d - %d\t", getpid(), i);
      printf("This is the child process. My pid is %d and my parent's id is %d.\n", getpid(), getppid());
      printf("%d - %d :\t-\n", getpid(), i);
    }
    else {
      printf("%d - %d\t", getpid(), i);
      printf("create child pid = %d\n", pid);
      printf("%d - %d\tThis is the parent process. My pid is %d and my child's id is %d.\n",  getpid(), i, getpid(), pid);
      printf("%d - %d :\t-\n", getpid(), i);
    }
    /*printf("-\n");*/
  }
  /*printf("pid = %d END\n", getpid());*/

  wait(NULL); wait(NULL); wait(NULL);
  return 0;
}
