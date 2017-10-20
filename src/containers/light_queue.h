#ifndef LIGHT_QUEUE_H
#define LIGHT_QUEUE_H

typedef struct Queue_ Queue;
typedef struct Node_ Node;

struct Queue_ {
	Node* head;
	Node* tail;
	int limit;
	int size;
};

struct Node_ {
	void* data;
	Node* next;
};

Queue* lq_create(int limit);
int lq_put(Queue* queue, void* data);
int lq_peek(Queue* queue);
void* lq_get(Queue* queue);
int lq_free(Queue* queue);

#endif /* LIGHT_QUEUE_H */
