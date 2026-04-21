Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix(char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        char c = exp[i];

        
        if (isalnum(c)) {
            printf("%c", c);
        }
        // If '(', push to stack
        else if (c == '(') {
            push(c);
        }
     
        else if (c == ')') {
            while (!isEmpty() && peek() != '(') {
                printf("%c", pop());
            }
            pop(); 
        }
        // Operator
        else {
            while (!isEmpty() && precedence(peek()) >= precedence(c)) {
                printf("%c", pop());
            }
            push(c);
        }
    }

    
    while (!isEmpty()) {
        printf("%c", pop());
    }
    printf("\n");
}

int main() {
    char exp[MAX];
    scanf("%s", exp);
    infixToPostfix(exp);
    return 0;
}
