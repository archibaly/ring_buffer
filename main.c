#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include "ring_buffer.h"

void *producer(void *args)
{
	int i;
	struct ring_buffer *buf = args;

	for (i = 0; ; i++) {
		push(buf, i);
		printf("produce %d\n", i);
		sleep(1);
	}
	return NULL;
}

void *consumer(void *args)
{
	int element;
	struct ring_buffer *buf = args;

	for (;;) {
		if (pop(buf, &element) == 0)
			printf("consume %d\n", element);
		sleep(2);
	}
	return NULL;
}

int main()
{
	pthread_t t1, t2;
	struct ring_buffer buf;

	init(&buf);

	pthread_create(&t1, NULL, producer, &buf);
	pthread_create(&t2, NULL, consumer, &buf);

	for (;;) {
		pause();
	}

	return 0;
}
