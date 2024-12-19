#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Enode {
    char ssn[15], name[20], dept[5], designation[10];
    int salary;
    long long phno;
    struct Enode *left, *right;
} *head = NULL, *tail;

void create(char s[], char n[], char d[], char des[], int sal, long long ph) {
    struct Enode *temp = (struct Enode *)malloc(sizeof(struct Enode));
    strcpy(temp->ssn, s); strcpy(temp->name, n); strcpy(temp->dept, d);
    strcpy(temp->designation, des); temp->salary = sal; temp->phno = ph;
    temp->left = tail; temp->right = NULL;
    if (!head) head = temp;
    else tail->right = temp;
    tail = temp;
}

void display() {
    struct Enode *temp = head; int count = 0;
    while (temp) {
        printf("SSN: %s, Name: %s, Dept: %s, Desig: %s, Sal: %d, Phone: %lld\n", 
                temp->ssn, temp->name, temp->dept, temp->designation, temp->salary, temp->phno);
        temp = temp->right; count++;
    }
    printf("Nodes: %d\n", count);
}

void insertFront(char s[], char n[], char d[], char des[], int sal, long long ph) {
    struct Enode *temp = (struct Enode *)malloc(sizeof(struct Enode));
    strcpy(temp->ssn, s); strcpy(temp->name, n); strcpy(temp->dept, d);
    strcpy(temp->designation, des); temp->salary = sal; temp->phno = ph;
    temp->right = head; temp->left = NULL;
    if (head) head->left = temp;
    else tail = temp;
    head = temp;
}

void deleteFront() {
    if (!head) { printf("Empty DLL\n"); return; }
    struct Enode *temp = head;
    head = head->right;
    if (head) head->left = NULL;
    else tail = NULL;
    free(temp);
}

void deleteEnd() {
    if (!tail) { printf("Empty DLL\n"); return; }
    struct Enode *temp = tail;
    tail = tail->left;
    if (tail) tail->right = NULL;
    else head = NULL;
    free(temp);
}

int main() {
    int choice, sal; long long ph;
    char s[15], n[20], d[5], des[10];
    while (1) {
        printf("\n1. Create\n2. Display\n3. Insert Front\n4. Delete Front\n5. Delete End\n6. Exit\n");
        printf("Choice: "); scanf("%d", &choice);
        if (choice == 6) break;
        switch (choice) {
            case 1: printf("SSN, Name, Dept, Desig, Salary, Phone: ");
                scanf("%s%s%s%s%d%lld", s, n, d, des, &sal, &ph); create(s, n, d, des, sal, ph); break;
            case 2: display(); break;
            case 3: printf("SSN, Name, Dept, Desig, Salary, Phone: ");
                scanf("%s%s%s%s%d%lld", s, n, d, des, &sal, &ph); insertFront(s, n, d, des, sal, ph); break;
            case 4: deleteFront(); break;
            case 5: deleteEnd(); break;
            default: printf("Invalid\n");
        }
    }
    return 0;
}