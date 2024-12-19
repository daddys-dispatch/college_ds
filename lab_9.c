#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct poly_node {
    float coef;
    int expx, expy, expz;
    struct poly_node *link;
} POLY;

POLY *getNode() {
    POLY *temp = (POLY *)malloc(sizeof(POLY));
    if (!temp) { printf("No Memory\n"); exit(0); }
    return temp;
}

void read_poly(POLY *head, int n) {
    POLY *new, *temp = head;
    for (int i = 0; i < n; i++) {
        new = getNode();
        printf("Enter Coef and Exps: ");
        scanf("%f%d%d%d", &new->coef, &new->expx, &new->expy, &new->expz);
        temp->link = new; temp = temp->link;
    }
    temp->link = head;
}

void print_poly(POLY *head) {
    POLY *temp = head->link;
    while (temp != head) {
        printf("%f*X^%d*Y^%d*Z^%d\t", temp->coef, temp->expx, temp->expy, temp->expz);
        temp = temp->link;
    }
    printf("\n");
}

POLY *add_poly(POLY *h1, POLY *h2) {
    POLY *temp1 = h1->link, *temp2, *result = getNode(), *tempres = result;
    while (temp1 != h1) {
        temp2 = h2->link;
        while (temp2 != h2) {
            if (temp1->expx == temp2->expx && temp1->expy == temp2->expy && temp1->expz == temp2->expz) {
                float cf = temp1->coef + temp2->coef;
                if (cf) { POLY *new = getNode(); new->coef = cf; new->expx = temp1->expx; 
                          new->expy = temp1->expy; new->expz = temp1->expz; tempres->link = new; tempres = new; }
                temp2 = temp2->link; break;
            }
            temp2 = temp2->link;
        }
        temp1 = temp1->link;
    }
    tempres->link = result;
    return result;
}

void evaluate(POLY *head) {
    float result = 0.0;
    int x, y, z;
    POLY *temp = head->link;
    printf("\nEnter x, y, z: ");
    scanf("%d%d%d", &x, &y, &z);
    while (temp != head) {
        result += temp->coef * pow(x, temp->expx) * pow(y, temp->expy) * pow(z, temp->expz);
        temp = temp->link;
    }
    printf("\nResult: %f\n", result);
}
int main() {
    int n1, n2;
    POLY *POLY1 = getNode(), *POLY2 = getNode(), *POLYSUM;
    POLY1->link = POLY1; POLY2->link = POLY2;
    printf("Enter terms for 1st and 2nd polynomials: ");
    scanf("%d%d", &n1, &n2);
    printf("\n1st Polynomial: "); read_poly(POLY1, n1); print_poly(POLY1);
    printf("\n2nd Polynomial: "); read_poly(POLY2, n2); print_poly(POLY2);
    POLYSUM = add_poly(POLY1, POLY2);
    printf("\nSum Polynomial: "); print_poly(POLYSUM);
    evaluate(POLYSUM);
    return 0;
}