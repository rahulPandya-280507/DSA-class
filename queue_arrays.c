#include <stdio.h>
#include <stdlib.h>

int isFull(int *r, int size);
int isEmpty(int *f, int *r);
void enqueue(int q[], int val, int *r, int *f, int size);
int dequeue(int q[],int *f, int *r);
void printArray(int q[], int f, int r);

int main() {
    int size = 10, f = -1, r = -1, count = 0;
    int queue[size], op;
    // menu
    while (1)
    {
        printf("Enter the operation number you'd like to perform:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            {
                int val;
                printf("Enter the value you want to enqueue: ");
                scanf("%d", &val);
                enqueue(queue, val, &r, &f, size);
                count++;
            }
            break;
        case 2:
            {
                int res = dequeue(queue, &f, &r);
                printf("the value dequeued is: %d\n", res);
                break;
            }
        case 3:
            {
                printArray(queue, f, r);
                break;
            }
        case 4:
            return 0;

        default:
            printf("Invalid option.\n");
        }
    }
    
}

void enqueue(int q[], int val, int *r, int *f, int size) {
    if(isFull(*r, size)) {
        printf("Queue Overflow\n");
    }else {
        *r++;
        q[*r] = val;
        if(*f == -1) {
            *f = 0;
        }
    }
}

int isFull (int *r, int size) {
    if(*r == size-1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty(int *f, int *r) {
    if(*f == -1 || *f>*r) {
        return 1;
    } 
    return 0;
}

int dequeue(int q[], int *f, int *r) {
    int a = -1;
    if(isEmpty(*f, *r)) {
        printf("Queue Underflow\n");
    } else {
        a = q[*f];
        *f++;
    }
    return a;
}

void printArray(int q[], int f, int r) {
    if(isEmpty(f, r)) {
        printf("Queue is empty\n");
        return;
    }

    for(int i = f; i <= r; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}