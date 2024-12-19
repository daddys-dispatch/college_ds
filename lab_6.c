#include <stdio.h>
#define MAX 5

char cqueue_arr[MAX];
int front = -1, rear = -1;

void insert(char item) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = rear = 0;
    else rear = (rear + 1) % MAX;
    cqueue_arr[rear] = item;
}

void del() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted: %c\n", cqueue_arr[front]);
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i != rear; i = (i + 1) % MAX)
        printf("%c ", cqueue_arr[i]);
    printf("%c\n", cqueue_arr[rear]);
}

int main() {
    int choice;
    char item;
    printf("\nMenu:\n1. Insert\n2. Delete\n0. Quit\n");
    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Input character for insertion: ");
                scanf(" %c", &item);
                insert(item);
                display();
                break;
            case 2:
                del();
                display();
                break;
            case 0:
                printf("Bye Bye...\n");
                break;
            default:
                printf("Wrong choice\n");
        }
    } while (choice != 0);
    return 0;
}