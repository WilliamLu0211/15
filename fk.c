#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int random_int(){
  int fd = open("/dev/random", O_RDONLY);
  int buff;
  read(fd, &buff, 4);
  buff = buff & (0xFFFFFF >> 1); // make buff nonnegative
  return buff;
}

int subprocess(){
  printf("PID: %d is sleeping...\n", getpid());
  int sleep_time = random_int() % 15 + 5;
  sleep(sleep_time);
  printf("PID: %d wakes up...\n", getpid());
  return sleep_time;
}

int main(){
  printf("forking...\n");
  int f, g;
  f = fork();
  if (!f){
    return subprocess();
  }
  g = fork();
  if (!g){
    return subprocess();
  }
  int status;
  int pid = wait(&status);
  printf("PID: %d was asleep for %d seconds.\n", pid, WEXITSTATUS(status));
  printf("parent program exits...\n");
  return 0;
}
