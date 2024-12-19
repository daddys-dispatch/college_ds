#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[20], usn[15], branch[5];
    int sem;
    long long ph;
    struct Node *next;
} Node;

Node *head = NULL, *tail = NULL;

void create_or_insert_tail(char *name, char *usn, char *branch, int sem, long long ph) {
    Node *temp = (Node *)malloc(sizeof(Node));
    strcpy(temp->name, name); strcpy(temp->usn, usn); strcpy(temp->branch, branch);
    temp->sem = sem; temp->ph = ph; temp->next = NULL;
    if (!head) head = tail = temp;
    else tail->next = temp, tail = temp;
}

void insert_head(char *name, char *usn, char *branch, int sem, long long ph) {
    Node *temp = (Node *)malloc(sizeof(Node));
    strcpy(temp->name, name); strcpy(temp->usn, usn); strcpy(temp->branch, branch);
    temp->sem = sem; temp->ph = ph; temp->next = head;
    head = temp;
}

void delete_head() {
    if (!head) return printf("List is empty\n");
    Node *temp = head;
    printf("Deleted: %s %s %s %d %lld\n", temp->name, temp->usn, temp->branch, temp->sem, temp->ph);
    head = head->next;
    free(temp);
}

void delete_tail() {
    if (!head) return printf("List is empty\n");
    if (head == tail) return delete_head();
    Node *temp = head;
    while (temp->next != tail) temp = temp->next;
    printf("Deleted: %s %s %s %d %lld\n", tail->name, tail->usn, tail->branch, tail->sem, tail->ph);
    free(tail); tail = temp; tail->next = NULL;
}

void display() {
    if (!head) return printf("List is empty\n");
    printf("List:\n");
    for (Node *temp = head; temp; temp = temp->next)
        printf("%s %s %s %d %lld\n", temp->name, temp->usn, temp->branch, temp->sem, temp->ph);
}

int main() {
    int choice, sem; long long ph; char name[20], usn[15], branch[5];
    printf("Menu:\n1. Create/Insert at Tail\n2. Insert at Head\n3. Delete from Head\n4. Delete from Tail\n5. Display\n0. Exit\n");
    while (1) {
        printf("Choice: ");
        scanf("%d", &choice);
        if (choice == 0) break;
        if (choice == 1 || choice == 2) {
            printf("Enter Name USN Branch Sem Ph: ");
            scanf("%s %s %s %d %lld", name, usn, branch, &sem, &ph);
            (choice == 1 ? create_or_insert_tail : insert_head)(name, usn, branch, sem, ph);
        } else if (choice == 3) delete_head();
        else if (choice == 4) delete_tail();
        else if (choice == 5) display();
        else printf("Invalid choice\n");
    }
    return 0;
}