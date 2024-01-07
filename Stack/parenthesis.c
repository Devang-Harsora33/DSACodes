#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure to represent a stack
struct Stack
{
    int top;
    char items[MAX_SIZE];
};

// Function to initialize an empty stack
void initialize(struct Stack *stack)
{
    stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack *stack)
{
    return (stack->top == -1);
}

// Function to check if the stack is full
bool isFull(struct Stack *stack)
{
    return (stack->top == MAX_SIZE - 1);
}

// Function to push a character onto the stack
void push(struct Stack *stack, char data)
{
    if (isFull(stack))
    {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->items[++stack->top] = data;
}

// Function to pop a character from the stack
char pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->items[stack->top--];
}

// Function to check if parentheses are balanced in the expression
bool areParenthesesBalanced(char expr[])
{
    struct Stack stack;
    initialize(&stack);
    char popped;

    for (int i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            push(&stack, expr[i]);
        }
        else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}')
        {
            popped = pop(&stack);
            if ((expr[i] == ')' && popped != '(') ||
                (expr[i] == ']' && popped != '[') ||
                (expr[i] == '}' && popped != '{'))
            {
                return false; // Unbalanced parentheses
            }
        }
    }

    return isEmpty(&stack); // Expression is balanced if the stack is empty
}

int main()
{
    char expr[100];
    printf("Enter an expression: ");
    scanf("%s", expr);

    if (areParenthesesBalanced(expr))
    {
        printf("The parentheses are balanced.\n");
    }
    else
    {
        printf("The parentheses are not balanced.\n");
    }

    return 0;
}
