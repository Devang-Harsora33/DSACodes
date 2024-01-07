// CIRCULAR QUEUE USING LINKED LIST
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
        rear->next = front; // Circular link for the first node
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Circular link
    }
}

int dequeue()
{
    int x = -1;
    if (front == NULL)
    {
        printf("Queue is empty!");
    }
    else
    {
        struct Node *temp = front;

        // If there's only one element
        if (front == rear)
        {
            x = front->data;
            front = rear = NULL;
        }
        else
        {
            x = front->data;
            front = front->next;
            rear->next = front; // Update circular link
        }

        free(temp);
    }
    return x;
}

void display()
{
    if (front == NULL)
    {
        printf("Queue is empty!");
    }
    else
    {
        struct Node *temp = front;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != front);
    }
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

// STACK USING LINKED LIST
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int val);
int pop();
int peek();
void display();

int main()
{
    int val, option;

    do
    {
        printf("\n ****MAIN MENU****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\n Enter the number to be pushed on the stack: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            val = pop();
            if (val != -1)
                printf("\n The value deleted from the stack is: %d", val);
            break;
        case 3:
            val = peek();
            if (val != -1)
                printf("\n The value stored at the top of the stack is: %d", val);
            break;
        case 4:
            display();
            break;
        }
    } while (option != 5);

    return 0;
}

void push(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("\n Memory allocation failed. Unable to push onto the stack.");
        return;
    }

    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    if (top == NULL)
    {
        printf("\n STACK UNDERFLOW");
        return -1;
    }

    int val = top->data;
    struct Node *temp = top;
    top = top->next;
    free(temp);
    return val;
}

void display()
{
    if (top == NULL)
    {
        printf("\n STACK IS EMPTY");
        return;
    }

    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("\n %d", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int peek()
{
    if (top == NULL)
    {
        printf("\n STACK IS EMPTY");
        return -1;
    }

    return top->data;
}
