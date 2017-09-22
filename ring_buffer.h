#ifndef _RING_BUFFER_H_
#define _RING_BUFFER_H_

#define MAX_BUFFER_SIZE	1024

struct ring_buffer {
	int read_index;
	int write_index;
	int buffer[MAX_BUFFER_SIZE];
};

void init(struct ring_buffer *rb);
int push(struct ring_buffer *rb, int element);
int pop(struct ring_buffer *rb, int *element);

#endif /* _RING_BUFFER_H_ */
