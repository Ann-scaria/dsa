// DEQUE - Double Ended Queue (Circular)

#include <stdio.h>
#define MAX 10

int deque[MAX];
int front = -1, rear = -1;

int isFull() {
    return ( (front == 0 && rear == MAX - 1) || (front == rear + 1) );
}

int isEmpty() {
    return (front == -1);
}

void insertFront(int value) {
    if (isFull()) {
        printf("Deque is full\n");
        return;
    }

    if (front == -1) {                 // first element
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;               // wrap to end
    } else {
        front--;
    }

    deque[front] = value;
    printf("Inserted at front: %d\n", value);
}

void insertRear(int value) {
    if (isFull()) {
        printf("Deque is full\n");
        return;
    }

    if (front == -1) {                 // first element
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;                      // wrap to start
    } else {
        rear++;
    }

    deque[rear] = value;
    printf("Inserted at rear: %d\n", value);
}

void deleteFront() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deleted from front: %d\n", deque[front]);

    if (front == rear) {               // only one element
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;                     // wrap
    } else {
        front++;
    }
}

void deleteRear() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deleted from rear: %d\n", deque[rear]);

    if (front == rear) {               // only one element
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;                // wrap
    } else {
        rear--;
    }
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements are: ");
    int i = front;

    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int n, choice, value;

    printf("Enter the number of operations to be performed: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nCHOOSE OPERATION:\n");
        printf("1 - Insert at front\n");
        printf("2 - Insert at rear\n");
        printf("3 - Delete from front\n");
        printf("4 - Delete from rear\n");
        printf("5 - Display\n");
        printf("6 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                printf("Enter the value: ");
                scanf("%d", &value);
                insertRear(value);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
