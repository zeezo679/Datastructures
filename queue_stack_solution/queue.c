#include "queue.h"



void createQueue(queue *pq){
    pq->size = 0;
    pq->rear = -1;
    pq->front = 0;  //place to be served
}

void enqueue(queueEntry el, queue *pq){
    pq->entry[(++pq->rear)%MAX_SIZE] = el;
    pq->size++;
}

queueEntry dequeue(queue *pq){
    pq->size--;
    queueEntry el = pq->entry[pq->front];
    pq->front = (pq->front+1)%MAX_SIZE;
    return el;
}

int queueEmpty(queue *pq){
    return !pq->size;
}

int queueFull(queue *pq){
    return pq->size == MAX_SIZE;
}


int queueSize(queue *pq){
    return pq->size;
}

void clearQueue(queue *pq){
    pq->size = 0;
    pq->rear = -1;
    pq->front = 0;  //place to be served
}

void traverseQueue(queue *pq, void(*pf)(queueEntry)){
    int pos, i;
    for(pos = pq->front, i = 0; i < pq->size; i++){
        (*pf)(pq->entry[pos]);
        pos = (pos+1)%MAX_SIZE;
    }
}
