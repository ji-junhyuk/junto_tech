#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define true 1
#define NUM_PHILS 50000

enum {THINKING, HUNGRY, EATING} state[NUM_PHILS];

pthread_mutex_t mutex_lock;
pthread_cond_t cond_vars[NUM_PHILS];

int leftOf(int idx)
{
	return (idx + NUM_PHILS - 1) % NUM_PHILS;
}

int rightOf(int idx)
{
	return (idx + 1) % NUM_PHILS;
}

void think(int id)
{
	printf("%d: Now, I'm thinking...\n", id);
	usleep((1 + rand() % 50) * 10000);
}

void eat(int id)
{
	printf("%d: Now, I'm eating...\n", id);
	usleep((1 + rand() % 50) * 10000);
}

void test(int idx)
{
	if (state[idx] == HUNGRY && 
			state[leftOf(idx)] != EATING && state[rightOf(idx)] != EATING)
	{
		state[idx] = EATING;
		pthread_cond_signal(&cond_vars[idx]);
	}
}

void pickup(int idx)
{
	pthread_mutex_lock(&mutex_lock);

	state[idx] = HUNGRY;
	test(idx);
	while (state[idx] != EATING)
		pthread_cond_wait(&cond_vars[idx], &mutex_lock);
	pthread_mutex_unlock(&mutex_lock);
}

void putdown(int idx)
{
	pthread_mutex_lock(&mutex_lock);

	state[idx] = THINKING;
	test(leftOf(idx));
	test(rightOf(idx));
	
	pthread_mutex_unlock(&mutex_lock);
}

void *philosopher(void *param)
{
	int id = *((int *)param);
	while (1)
	{
		think(id);
		pickup(id);
		eat(id);
		putdown(id);
	}
}

void init()
{
	int idx;
	for (idx = 0; idx < NUM_PHILS; ++idx)
	{
		state[idx] = THINKING;
		pthread_cond_init(&cond_vars[idx], NULL);
	}
	pthread_mutex_init(&mutex_lock, NULL);
	srand(time(0));
}

		
int main()
{
	int idx;
	pthread_t tid;
	init();
	for (idx = 0; idx < NUM_PHILS; ++idx)
		pthread_create(&tid, NULL, philosopher, (void *)&idx);
	for (idx = 0; idx < NUM_PHILS; ++idx)
		pthread_join(tid, NULL);
	return (0);
}
