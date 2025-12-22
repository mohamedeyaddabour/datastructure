/*
 * Description: Implementation of Dijkstra's Shunting Yard algorithm.
 * Converts an Infix expression (like A+B) to Postfix (AB+).
 * I included a simple Stack implementation inside this file so it runs standalone.
 * It handles operator precedence (*, / > +, -) and parentheses.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// --- Stack Implementation for char ---
struct Stack {
    int top;
    char items[MAX];
};

void push(struct Stack* s, char c) {
    if (s->top >= MAX - 1) return;
    s->items[++(s->top)] = c;
}

char pop(struct Stack* s) {
    if (s->top == -1) return -1;
    return s->items[(s->top)--];
}

char peek(struct Stack* s) {
    if (s->top == -1) return -1;
    return s->items[s->top];
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to return precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Main Shunting Yard Logic
void infixToPostfix(char* infix) {
    struct Stack s;
    s.top = -1;
    char postfix[MAX];
    int i = 0, k = 0;
    
    while (infix[i] != '\0') {
        char token = infix[i];

        // If operand, add to output
        if (isalnum(token)) {
            postfix[k++] = token;
        }
        // If '(', push to stack
        else if (token == '(') {
            push(&s, token);
        }
        // If ')', pop until '('
        else if (token == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s); // Remove '('
        }
        // If operator
        else if (isOperator(token)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(token)) {
                postfix[k++] = pop(&s);
            }
            push(&s, token);
        }
        i++;
    }

    // Pop remaining operators
    while (!isEmpty(&s)) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0'; // Null terminate string

    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);
}

int main() {
    char expression[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(expression);
    return 0;
}