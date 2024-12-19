#include <stdio.h>
#include <math.h>
#define MAX 20

struct stack {
    int top;
    float str[MAX];
} s;

char postfix[MAX];
void push(float);
float pop();
int isoperand(char);
float operate(float, float, char);

int main() {
    int i = 0;
    printf("Enter Suffix Expression: ");
    scanf("%s", postfix);
    float ans, op1, op2;
    while(postfix[i] != '\0') {
        if(isoperand(postfix[i])) push(postfix[i] - 48);
        else {
            op1 = pop();
            op2 = pop();
            ans = operate(op1, op2, postfix[i]);
            push(ans);
            printf("%f %c %f = %f\n", op2, postfix[i], op1, ans);
        }
        i++;
    }
    printf("Result: %f\n", s.str[s.top]);
    return 0;
}
int isoperand(char x) {
    return (x >= '0' && x <= '9');
}
void push(float x) {
    if(s.top < MAX - 1) s.str[++s.top] = x;
    else printf("Stack Overflow\n");
}
float pop() {
    return (s.top != -1) ? s.str[s.top--] : -1;
}

float operate(float op1, float op2, char a) {
    switch(a) {
        case '+': return op2 + op1;
        case '-': return op2 - op1;
        case '*': return op2 * op1;
        case '/': return op2 / op1;
        case '^': return pow(op2, op1);
    }
}