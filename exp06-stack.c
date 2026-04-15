// implementing stack using arrays
#include <stdio.h>
#include <stdlib.h>

// structure definition 
struct Stack {
    int top;
    int size;
    int *arr;
};

// Function prototyping
int isEmpty(struct Stack *s);
int isFull(struct Stack *s);
void push(int value, struct Stack *s);
int pop(struct Stack *s);
int peek(struct Stack *s, int index);
int stackTop(struct Stack *s);
int stackBottom(struct Stack *s);

int main() {
    // a menu driven program in order to perform stack operations
    // creating stack and assigning memory
    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int*)malloc(s->size*sizeof(int));

    int index;
    
    //menu
    int operation;
     int stack_top, stack_bottom;
    while(1) {
        printf("\nEnter the operation you'd like to perform: \n1. Push\n2. Pop\n3. Check if the stack is empty or not\n4. Peek\n5. Stack Top\n6. Stack Bottom\n7. Exit\n");
        scanf("%d", &operation);

        if(operation == 7) {
            break;
        }
        
        switch(operation) {
            case 1: {
                int val;
                printf("Enter the value you want to push: ");
                scanf("%d", &val);
                push(val, s);
                break;
            }
            case 2: {
                int val = pop(s);
                printf("Popped element: %d\n", val);
                break;
            }
            case 3: {
                if(isEmpty(s)) {
                    printf("The stack is empty\n");
                } else {
                    printf("The stack is not empty\n");
                }
                break;
            }
            case 4:
                printf("Enter the position you want to view the element of: ");
                scanf("%d", &index);
                printf("The value at index %d is: %d\n", index, peek(s, index));
                break;

            case 5:
                if (isEmpty) {
                    printf("Cannot find the value, as the stack is empty!\n");
                    break;
                } else {
                    stack_top = stackTop(s);
                    printf("The top element of the stack is: %d\n", stack_top);
                    break;
                }

            case 6:
                if (isEmpty) {
                    printf("Cannot find the value, as the stack is empty!\n");
                    break;
                } else {
                    stack_bottom = stackBottom(s);
                    printf("The bottom element of the stack is: %d\n", stack_top);
                    break;
                }

            default:
                printf("Please enter any one of the options!\n");
        }
    }
    free(s->arr);
    free(s);
    return 0; 
}


int isEmpty(struct Stack *s) {
    if(s->top == -1){
        return 1;
    } else {
        return 0;
    }
}

int isFull(struct Stack *s) {
    if(s->top == s->size-1) {
        return 1;
    } else {
        return 0;
    }
}

void push(int value, struct Stack *s) {
    if(isFull(s)) {
        printf("Stack Overflow\n");
    } else {
        s->top++;
        s->arr[s->top] = value;
    }
}

int pop(struct Stack *s) {
    if(isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        int value = s->arr[s->top];
        s->top = s->top - 1;
        return value;
    }
}

int peek(struct Stack *s, int index) {
    int arrayInd = s->top - index + 1;
    if(arrayInd < 0) {
        printf("Not a valid position, No element found!\n");
        return -1;
    } else {
        return s->arr[arrayInd];
    }
}

int stackTop(struct Stack *s) {
    return s->arr[s->top];
}

int stackBottom(struct Stack *s) {
    return s->arr[0];
}