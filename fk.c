#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  srand( time(NULL) );
  printf("forking...\n");
  int f = fork();
  if (!f){
    printf("PID: %d is sleeping...\n", getpid());
    int sleep_time = rand() % 15 + 5;
    sleep(sleep_time);
    printf("waking up...\n");
    return 0;
  }

  return 0;
}
