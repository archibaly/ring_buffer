#include <string.h>

#include "ring_buffer.h"

void init(struct ring_buffer *rb)
{
	rb->read_index = 0;
	rb->write_index = 0;
	memset(rb->buffer, 0, sizeof(rb->buffer));
}

int push(struct ring_buffer *rb, int element)
{
	int next = (rb->write_index + 1) % sizeof(rb->buffer);

	if (next == rb->read_index) {
		return -1;
	} else {
		rb->buffer[rb->write_index] = element;
		rb->write_index = next;
	}
	return 0;
}

int pop(struct ring_buffer *rb, int *element)
{
	if (rb->read_index == rb->write_index) {
		return -1;
	} else {
		*element = rb->buffer[rb->read_index];
		rb->read_index = (rb->read_index + 1) % sizeof(rb->buffer);
	}
	return 0;
}

int empty(const struct ring_buffer *rb)
{
	return rb->read_index == rb->write_index;
}

int full(const struct ring_buffer *rb)
{
	int next = (rb->write_index + 1) % sizeof(rb->buffer);

	if (rb->read_index == next)
		return 1;
	else
		return 0;
}
