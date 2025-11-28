#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    }

    if (front == -1) {      // first element
        front = 0;
    }

    rear++;
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Dequeued: %d\n", queue[front]);
    front++;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int n, choice, value;

    printf("Enter the number of operations to be performed: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nCHOOSE OPERATION:\n");
        printf("1 - Enqueue\n");
        printf("2 - Dequeue\n");
        printf("3 - Display\n");
        printf("4 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
