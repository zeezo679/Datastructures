#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#define MAX_SIZE 100
typedef char queueEntry;

typedef struct queue{
    int front;
    int rear;
    int size;
    queueEntry entry[MAX_SIZE];
}queue;

void createQueue(queue *);
int queueSize(queue *);
void enqueue(queueEntry, queue *);
queueEntry dequeue(queue *);
int queueEmpty(queue *);
int queueFull(queue *);
void clearQueue(queue *);
void traverseQueue(queue *, void(*pf)(queueEntry));
#endif // QUEUE_H_INCLUDED
