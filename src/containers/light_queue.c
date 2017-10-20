
#include <stdlib.h>

#include "light_queue.h"

Queue* lq_create(int limit) {
	Queue* q = malloc(sizeof *q);
	
	q->limit = limit;
	q->size = 0;
	q->head = NULL;
	q->tail = NULL;
	
	return q;
}

int lq_put(Queue* queue, void* data) {
	if(queue->size == queue->limit){
		return 1;
	}
	
	Node* n = malloc(sizeof *n);
	n->data = data;
	n->next = NULL;
	
	if(queue->size == 0) {
		queue->head = n;
		queue->tail = n;
	} else {
		queue->tail->next = n;
		queue->tail = n;
	}
	queue->size++;
	
	return 0;
}

int lq_peek(Queue* queue) {
	return queue->size;
}

void* lq_get(Queue* queue) {
	if(queue->size == 0){
		return NULL;
	}
	Node* n = queue->head->data;
	void* data = n->data;
	
	queue->head = n->next;
	queue->size--;
	free(n);
	
	return data;
}

int lq_free(Queue* queue) {
	void* n;
	while((n = lq_get(queue))){
		free(n);
	}
	return 0;
}

