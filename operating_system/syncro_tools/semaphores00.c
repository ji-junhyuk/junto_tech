#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int sum = 0;

sem_t sem;

void	*counter(void *param)
{
	int idx;
	for (idx = 0; idx < 10000; ++idx)
	{
		sem_wait(&sem);
		++sum;
		sem_post(&sem);
	}
	pthread_exit(0);
}

int main()
{
	pthread_t tid1, tid2;
	sem_init(&sem, 0, 1);
	pthread_create(&tid1, NULL, counter, NULL);
	pthread_create(&tid2, NULL, counter, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	printf("sum = %d\n", sum);
}
