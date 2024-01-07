// STACK USING ARR//  AND C-QUEUE BELOW
#include <stdio.h>
#include <stdlib.h>

#define MAX 3 // Altering this value changes the size of the stack created

int st[MAX], top = -1;

void push(int st[], int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);
void reverseStack(int st[]);

void push(int st[], int val)
{
    if (top == MAX - 1)
    {
        printf("\n STACK OVERFLOW");
    }
    else
    {
        top++;
        st[top] = val;
    }
}

int pop(int st[])
{
    int val;

    if (top == -1)
    {
        printf("\n STACK UNDERFLOW");
        return -1;
    }
    else
    {
        val = st[top];
        top--;
        return val;
    }
}

void display(int st[])
{
    int i;

    if (top == -1)
        printf("\n STACK IS EMPTY");
    else
    {
        for (i = top; i >= 0; i--)
            printf("\n %d", st[i]);

        printf("\n");
    }
}

int peek(int st[])
{
    if (top == -1)
    {
        printf("\n STACK IS EMPTY");
        return -1;
    }
    else
    {
        return (st[top]);
    }
}

void reverseStack(int st[])
{
    int aux[MAX], i;

    // Push all elements to the auxiliary stack
    for (i = top; i >= 0; i--)
    {
        push(aux, st[i]);
    }

    // Pop elements from the auxiliary stack back to the original stack
    for (i = 0; i <= top; i++)
    {
        st[i] = pop(aux);
    }
}
int main(int argc, char *argv[])
{
    int val, option;

    do
    {
        printf("\n ****MAIN MENU****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. REVERSE");
        printf("\n 6. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\n Enter the number to be pushed on the stack: ");
            scanf("%d", &val);
            push(st, val);
            break;
        case 2:
            val = pop(st);
            if (val != -1)
                printf("\n The value deleted from the stack is: %d", val);
            break;
        case 3:
            val = peek(st);
            if (val != -1)
                printf("\n The value stored at the top of the stack is: %d", val);
            break;
        case 4:
            display(st);
            break;
        case 5:
            reverseStack(st);
            printf("\n Stack reversed");
            break;
        }
    } while (option != 6);

    return 0;
}

// CIRCULAR QUEUE USING ARRAY
#include <stdio.h>
#include <conio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int val)
{
    if (front == (rear + 1) % SIZE) // rear = size - 1 in queue
    {
        printf("Queue is full!");
    }
    else
    {
        if (rear == -1)
            front++;
        rear = (rear + 1) % SIZE; // rear++ in queue
        queue[rear] = val;
    }
}

int dequeue()
{
    int x = -1;
    if (front == -1)
    {
        printf("Queue is empty!");
    }
    else
    {
        x = queue[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE; // front++ in queue
    }
    return x;
}

void display()
{
    int i = front;
    while (i != rear)
    {
        printf("%d -> ", queue[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d", queue[i]);
}

int main()
{
    int choice, val;
    do
    {
        printf("\n\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value you want to enqueue: ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            printf("The value dequeued is: %d", dequeue());
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        default:
            printf("Invalid choice!");
            choice = 4;
            break;
        }
    } while (choice != 4);

    return 0;
}
