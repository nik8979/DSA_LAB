#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char data[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (stack->top < MAX_SIZE - 1) {
        stack->data[++stack->top] = item;
    }
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[stack->top--];
    }
    return '\0';
}

bool areParenthesesValid(const char* expression) {
    struct Stack parentheses;
    initialize(&parentheses);

    for (int i = 0; i < strlen(expression); i++) {
        char c = expression[i];
        if (c == '(' || c == '{' || c == '[') {
            push(&parentheses, c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(&parentheses)) {
                return false; // Unmatched closing parenthesis
            }

            char top = pop(&parentheses);

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false; // Mismatched opening and closing parentheses
            }
        }
    }

    return isEmpty(&parentheses); // All parentheses are matched
}

int main() {
    char expression[MAX_SIZE];
    printf("Enter an expression: ");
    scanf("%s", expression);

    if (areParenthesesValid(expression)) {
        printf("Parentheses are valid.\n");
    } else {
        printf("Parentheses are not valid.\n");
    }

    return 0;
}
