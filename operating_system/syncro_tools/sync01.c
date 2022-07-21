#include <stdio.h>
#include <pthread.h>

int sum = 0;

void	*run1(void	*param)
{
	int	idx;
	for (idx = 0; idx < 10000; ++idx)
		++sum;
	pthread_exit(0);
}

void	*run2(void	*param)
{
	int	idx;
	for (idx = 0; idx < 10000; ++idx)
		--sum;
	pthread_exit(0);
}

int main(void)
{
	pthread_t tid1, tid2;
	pthread_create(&tid1, NULL, run1, NULL);
	pthread_create(&tid2, NULL, run2, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	printf("%d\n", sum);
}
