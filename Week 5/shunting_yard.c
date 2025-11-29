#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// --- STACK STRUCTURE ---
struct Stack {
    int top;
    char items[MAX];
};

// --- STACK OPERATIONS ---
void push(struct Stack* s, char c) {
    if (s->top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = c;
}

char pop(struct Stack* s) {
    if (s->top == -1) {
        return -1; // Stack empty
    }
    return s->items[(s->top)--];
}

char peek(struct Stack* s) {
    if (s->top == -1) {
        return -1;
    }
    return s->items[s->top];
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// --- HELPER FUNCTIONS ---

// Function to check precedence of operators
// Higher return value = higher precedence
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Function to check if character is operand (A-Z, a-z, 0-9)
int isOperand(char c) {
    return isalnum(c); 
}

// --- SHUNTING YARD ALGORITHM ---
void infixToPostfix(char* infix, char* postfix) {
    struct Stack s;
    s.top = -1; // Initialize stack
    int i, j = 0;
    char token;

    for (i = 0; infix[i] != '\0'; i++) {
        token = infix[i];

        // 1. If Operand, add to output
        if (isOperand(token)) {
            postfix[j++] = token;
        }
        // 2. If Left Parenthesis, push to stack
        else if (token == '(') {
            push(&s, token);
        }
        // 3. If Right Parenthesis
        else if (token == ')') {
            // Pop until '(' is found
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s); // Discard the '('
        }
        // 4. If Operator
        else {
            // While stack top has >= precedence, pop it
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(token)) {
                postfix[j++] = pop(&s);
            }
            push(&s, token);
        }
    }

    // 5. Pop any remaining operators
    while (!isEmpty(&s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0'; // Null-terminate string
}

// --- MAIN TEST ---
int main() {
    char infix1[] = "a*b+c";
    char postfix1[MAX];

    char infix2[] = "(a+b)*c";
    char postfix2[MAX];
    
    // Test Case 1
    infixToPostfix(infix1, postfix1);
    printf("Infix:   %s\n", infix1);
    printf("Postfix: %s\n\n", postfix1);

    // Test Case 2
    infixToPostfix(infix2, postfix2);
    printf("Infix:   %s\n", infix2);
    printf("Postfix: %s\n", postfix2);

    return 0;
}