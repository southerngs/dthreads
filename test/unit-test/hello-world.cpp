#include <pthread.h>
#include <stdio.h>

void *spawned(void *arg)
{
  int tid = *(int *)arg;
  printf("thread id: %d\n", tid);
}

pthread_t threads[2];
int id0 = 0;

int main()
{
  printf("main thread start\n");
  pthread_create(&threads[0], NULL, spawned, &id0);
  printf("main join thread 0\n");
  pthread_join(threads[0], NULL);
  printf("main complete\n");
}
