#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];

pthread_mutex_t mutex;
sem_t empty, full;

int in = 0, out = 0;

void insert_item(int item)
{
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);

	buffer[in] = item;
	in = (in + 1) % BUFFER_SIZE;
	printf("Producer: inserted $%d\n", item);

	pthread_mutex_unlock(&mutex);
	sem_post(&full);
}

void remove_item(int *item)
{
	sem_wait(&full);
	pthread_mutex_lock(&mutex);

	*item = buffer[out];
	out = (out + 1) % BUFFER_SIZE;
	printf("Consumer: inserted $%d\n", *item);

	pthread_mutex_unlock(&mutex);
	sem_post(&full);
}

void *producer(void *param)
{
	int item;
	while (1)
	{
		usleep((1 + rand() % BUFFER_SIZE) * 100000);
		item = 1000 + rand() % 1000;
		insert_item(item); // critical section
	}
}

void *consumer(void *param)
{
	int item;
	while (1)
	{
		usleep((1 + rand() % BUFFER_SIZE) * 100000);
		remove_item(&item);
	}
}

int main(int argc, char *argv[])
{
	int i, numOfProducers = 5, numOfConsumers = 5;
	pthread_t tid;

	pthread_mutex_init(&mutex, NULL);
	sem_init(&empty, 0, BUFFER_SIZE);
	sem_init(&full, 0, 0);
	srand(time(0));

	for (int idx = 0; idx < numOfProducers; ++idx)
		pthread_create(&tid, NULL, producer, NULL);
	for (int idx = 0; idx < numOfProducers; ++idx)
		pthread_create(&tid, NULL, consumer, NULL);
	sleep(1);
	return 0;
}
