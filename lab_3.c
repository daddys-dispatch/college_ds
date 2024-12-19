#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX], top = -1, temp, item;

void push() {
    if (top == MAX - 1) printf("Stack Overflow\n");
    else { 
        printf("Enter element: "); 
        scanf("%d", &item); 
        stack[++top] = item; 
        temp = top; 
    }
}

void pop() {
    if (top == -1) printf("Stack Underflow\n");
    else item = stack[top--];
}

void pali() {
    int rev[MAX], i = 0, flag = 1, t = top;
    while (t != -1) rev[i++] = stack[t--];
    for (i = 0; i <= temp; i++) if (stack[i] != rev[i]) { flag = 0; break; }
    printf(flag ? "Palindrome\n" : "Not Palindrome\n");
}

void display() {
    if (top == -1) printf("Stack is Empty\n");
    else for (int i = top; i >= 0; i--) printf("%d\n", stack[i]);
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Push 2.Pop 3.Palindrome 4.Display 5.Exit\nEnter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: push(); break;
            case 2: pop(); if (top != -1) printf("Popped: %d\n", item); break;
            case 3: pali(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}