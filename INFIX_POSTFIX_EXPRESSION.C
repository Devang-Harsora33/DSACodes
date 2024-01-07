#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack
{
    char items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *stack)
{
    stack->top = -1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, char value)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Stack Overflow! Cannot push %c\n", value);
        return;
    }
    stack->items[++stack->top] = value;
}

char pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow! Cannot pop from an empty stack\n");
        return '\0';
    }
    return stack->items[stack->top--];
}

char peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        return '\0';
    }
    return stack->items[stack->top];
}

int isOperand(char ch)
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

void infixToPostfix(char infix[], char postfix[])
{
    struct Stack stack;
    initialize(&stack);

    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if (isOperand(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(&stack, ch);
        }
        else if (ch == ')')
        {
            while (!isEmpty(&stack) && peek(&stack) != '(')
            {
                postfix[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && peek(&stack) != '(')
            {
                printf("Invalid expression: Unmatched parentheses\n");
                return;
            }
            else
            {
                pop(&stack); // Remove '(' from stack
            }
        }
        else
        {
            while (!isEmpty(&stack) && precedence(ch) <= precedence(peek(&stack)))
            {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (!isEmpty(&stack))
    {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';
}

void infixToPrefix(char infix[], char prefix[])
{
    struct Stack stack;
    initialize(&stack);

    int i, j = 0;

    // Reverse the infix expression
    for (i = strlen(infix) - 1; i >= 0; i--)
    {
        char ch = infix[i];

        if (ch == '(')
        {
            prefix[j++] = ')';
        }
        else if (ch == ')')
        {
            prefix[j++] = '(';
        }
        else
        {
            prefix[j++] = ch;
        }
    }

    prefix[j] = '\0';

    // Now, treat the reversed infix expression as postfix
    infixToPostfix(prefix, prefix);

    // Reverse the postfix expression to get the prefix expression
    int len = strlen(prefix);
    for (i = 0; i < len / 2; i++)
    {
        char temp = prefix[i];
        prefix[i] = prefix[len - 1 - i];
        prefix[len - 1 - i] = temp;
    }
}

int main()
{
    char infix[MAX_SIZE], postfix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);

    printf("\nPostfix Expression: %s\n", postfix);
    printf("Prefix Expression: %s\n", prefix);

    return 0;
}
