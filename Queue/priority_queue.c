#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data, priority;
    struct Node *next;
} *start = NULL;

void insert()
{
    struct Node *newNode, *temp, *pre;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    int d, p;
    printf("Enter the data: ");
    scanf("%d", &d);
    printf("Enter the priority: ");
    scanf("%d", &p);
    newNode->data = d;
    newNode->priority = p;
    if (!start || (newNode->priority < start->priority))
    {
        newNode->next = start;
        start = newNode;
    }
    else
    {
        temp = start;
        while (temp != NULL && temp->priority <= p)
        {
            pre = temp;
            temp = temp->next;
        }
        pre->next = newNode;
        newNode->next = temp;
    }
}

void del()
{
    if (!start)
        printf("No elements!");
    else
    {
        struct Node *temp = start;
        printf("Deleted element: %d", temp->data);
        start = temp->next;
        free(temp);
    }
}

void display()
{
    struct Node *temp = start;
    while (temp)
    {
        printf("Data: %d Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

int main()
{
    int choice;
    do
    {
        printf("Menu:\n");
        printf("1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            insert();
            break;
        }
        case 2:
        {
            del();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
            exit(0);

        default:
            printf("Invalid choice");
        }
    } while (choice != 4);
    return 0;
}