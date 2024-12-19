#include <stdio.h>
#include <stdlib.h>

int *ht, key[20], n, m, h_index, count = 0;

void insert(int key) {
    h_index = key % m;
    while (ht[h_index] != -1)
        h_index = (h_index + 1) % m;
    ht[h_index] = key;
    count++;
}

void display() {
    if (count == 0) {
        printf("\nHash Table is empty\n");
        return;
    }
    printf("\nHash Table contents:\n");
    for (int i = 0; i < m; i++)
        printf("T[%d] --> %s\n", i, ht[i] != -1 ? (char[12]){0} + sprintf((char[12]){0}, "%d", ht[i]) : "Empty");
}

int main() {
    printf("\nEnter the number of employee records (N): ");
    scanf("%d", &n);

    if (n > 20) {
        printf("Maximum allowed records is 20. Please enter a valid number.\n");
        return 0;
    }

    printf("\nEnter the size of hash table (m, 2-digit): ");
    scanf("%d", &m);

    ht = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        ht[i] = -1;

    printf("\nEnter the four-digit key values (K) for N Employee Records:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &key[i]);

    for (int i = 0; i < n; i++) {
        if (count == m) {
            printf("\n~~~Hash table is full. Cannot insert the record with key %d~~~\n", key[i]);
            break;
        }
        insert(key[i]);
    }

    display();
    free(ht);

    return 0;
}
