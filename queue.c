#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int size;
    int f;
    int r;
    int *arr;
};

void enqueue(struct Queue *q, int val);
int dequeue(struct Queue *q);
int isFull(struct Queue *q);
int isEmpty(struct Queue *q);

int main() {
    struct Queue q;
    q.size = 10;
    q.f = q.r = -1;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 1);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q, 2);

    printf("The queue is empty: %d\n", isEmpty(&q));
    return 0;
}

void enqueue(struct Queue *q, int val) {
    if(isFull(q)) {
        printf("Queue overflow\n");
    } else {
        q->r++;
        q->arr[q->r] = val;
        if(q->f == -1) {
            q->f = 0;
        }
    }
}

int dequeue(struct Queue *q) {
    int a = -1;
    if(isEmpty(q)) {
        printf("No element to dequeue.\n");
    } else {
        a = q->arr[q->f];
        q->f ++;
    }
    return a;
}

int isFull(struct Queue *q) {
    if(q->r == q->size - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(struct Queue *q) {
    if(q->f == -1 || q->f > q->r) {
        return 1;
    } 
    return 0;
}