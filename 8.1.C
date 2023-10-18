#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
int head;
int tail;
int size;
int Q[];
}queue;

queue* new_queue(int size) {
queue *q = malloc(sizeof(queue) + size*sizeof(int));

q->head = 1;
q->tail = 1;
q->size = size;

return q;
}

int is_empty(queue *q) {
if(q->tail == q->head)
  return 1;
return 0;
}

int is_full(queue *q) {
if(q->head == q->tail+1)
  return 1;
return 0;
}

void enqueue(queue *q, int x) {
if(is_full(q)) {
  printf("Queue Overflow\n");
}
else {
  q->Q[q->tail] = x;
  if(q->tail == q->size)
    q->tail = 1;
  else
    q->tail = q->tail+1;
}
}

int dequeue(queue *q) {
if(is_empty(q)) {
  printf("Underflow\n");
  return -1000;
}
else {
  int x = q->Q[q->head];
  if(q->head == q->size) {
    q->head = 1;
  }
  else {
    q->head = q->head+1;
  }
  return x;
}
}

void display(queue *q) {
int i;
for(i=q->head; i<q->tail; i++) {
  printf("%d\n",q->Q[i]);
  if(i == q->size) {
    i = 0;
  }
}
}

int main() {
queue *q = new_queue(10);
enqueue(q, 10);
enqueue(q, 20);
enqueue(q, 30);
enqueue(q, 40);
enqueue(q, 50);
display(q);

printf("\n");

dequeue(q);
dequeue(q);
display(q);

printf("\n");

enqueue(q, 60);
enqueue(q, 70);
display(q);
return 0;
}
