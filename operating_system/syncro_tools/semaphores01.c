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
	pthread_t tid[5];
	sem_init(&sem, 0, 1);
	for (int idx = 0; idx < 5; ++idx)
		pthread_create(&tid[idx], NULL, counter, NULL);
	for (int idx = 0; idx < 5; ++idx)
		pthread_join(tid[idx], NULL);
	printf("sum = %d\n", sum);
}
