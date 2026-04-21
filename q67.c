Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


void push(Node** top, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}


int pop(Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int evaluatePostfix(char* exp) {
    Node* stack = NULL;
    char* token = strtok(exp, " ");

    while (token != NULL) {
        
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        } else {
            // Operator: pop two operands
            int b = pop(&stack);
            int a = pop(&stack);
            int result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
                default: printf("Invalid operator\n"); exit(1);
            }
            push(&stack, result);
        }
        token = strtok(NULL, " ");
    }
    return pop(&stack);
}

int main() {
    char exp[100];
    fgets(exp, sizeof(exp), stdin);
    
    exp[strcspn(exp, "\n")] = '\0';

    int result = evaluatePostfix(exp);
    printf("%d\n", result);

    return 0;
}
