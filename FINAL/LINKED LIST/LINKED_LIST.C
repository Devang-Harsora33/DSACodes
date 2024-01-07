#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
    int data;
    struct Node *next;
} *start;

void create()
{
    int no_of_nodes, i, data;
    printf("Enter number of nodes: ");
    scanf("%d", &no_of_nodes);
    struct Node *newNode, *temp;

    for (i = 0; i < no_of_nodes; i++)
    {

        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        if (start == NULL)
        {
            start = newNode;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void insert_before()
{
    int val, data;
    struct Node *newNode, *temp, *pre;
    printf("Enter data before which node is to be inserted: ");
    scanf("%d", &val);
    printf("Enter data:");
    scanf("%d", &data);

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    temp = start;
    if (temp->data == val)
    {
        newNode->next = start;
        start = newNode;
    }
    else
    {
        while (temp->data != val)
        {
            pre = temp;
            temp = temp->next;
        }
        pre->next = newNode;
        newNode->next = temp;
    }
}

void insert_after()
{
    int val, data;
    struct Node *newNode, *temp, *post;
    printf("Enter data after which node is to be inserted: ");
    scanf("%d", &val);
    printf("Enter data:");
    scanf("%d", &data);

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    temp = start;
    if (temp->data == val)
    {
        post = temp->next;
        temp->next = newNode;
        newNode->next = post;
    }
    else
    {
        while (temp->data != val)
        {
            temp = temp->next;
            post = temp->next;
        }
        temp->next = newNode;
        newNode->next = post;
    }
}

void del()
{
    int val;
    printf("Enter the element to be deleted: ");
    scanf("%d", &val);

    struct Node *temp, *pre;
    temp = start;
    if (temp->data == val)
    {
        start = temp->next;
        free(temp);
    }
    else
    {
        while (temp->data != val)
        {
            pre = temp;
            temp = temp->next;
        }
        pre->next = temp->next;
        free(temp);
    }
}

void display()
{

    struct Node *temp;
    temp = start;
    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            printf("%d -> ", temp->data);
        }
        else
        {
            printf("%d", temp->data);
        }

        temp = temp->next;
    }
}
void calculate_average()
{
    struct Node *temp = start;
    int sum = 0, count = 0;

    while (temp != NULL)
    {
        sum += temp->data;
        count++;
        temp = temp->next;
    }

    if (count > 0)
    {
        float average = (float)sum / count;
        printf("\nAverage of all elements: %.2f\n", average);
    }
    else
    {
        printf("\nList is empty.\n");
    }
}
void insertAtBeginning()
{
    int data;
    printf("Enter the element to be inserted at beginning:\t");
    scanf("%d", &data);
    struct Node *newNode, *temp;
    temp = start;
    newNode->data = data;
    newNode->next = start;
    start = newNode;
}

void insertAtEnd()
{
    int data;
    struct Node *newNode, *temp;
    printf("Enter the element to be inserted at End:\t");
    scanf("%d", &data);
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (start == NULL)
    {
        start = newNode;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void deleteAtBeginning()
{
    if (start == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = start;
    start = start->next;
    free(temp);

    printf("Element deleted from the beginning.\n");
}
void deleteAtEnd()
{
    struct Node *temp = start;
    struct Node *prev;
    if (start == NULL)
    {
        printf("The list is already empty\n");
        return;
    }
    // If there is only one node in the linked list then it should be removed from the memory
    else if (temp->next == NULL)
    {
        free(temp);
        start = NULL;
        return;
    }
    // Search for end of the linked list
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    // Remove the last link and remove the node from the memory
    prev->next = NULL;
    free(temp);
    printf("Deleted at the end \n");
}
int main()
{
    int i, iteration = 0;
    create();

    do
    {
        printf("\nMenu:\n");
        printf("1.Insert Before\n");
        printf("2.Insert After\n");
        printf("3.Delete\n");
        printf("4.Display\n");
        printf("5.Calculate Average\n");
        printf("6.Insert At Beginning\n");
        printf("7.Insert At End\n");
        printf("8.Delete At Beginning\n");
        printf("9.Delete At End\n");
        printf("10.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &i);

        switch (i)
        {
        case 1:
            insert_before();
            break;

        case 2:
            insert_after();
            break;

        case 3:
            del();
            break;

        case 4:
            display();
            break;

        case 5:
            calculate_average();
            break;
        case 6:
            insertAtBeginning();
            break;
        case 7:
            insertAtEnd();
            break;
        case 8:
            deleteAtBeginning();
            break;
        case 9:
            deleteAtEnd();
            break;
        case 10:
            exit(0);
            break;

        default:
            printf("Invalid Input!");
        }

        iteration++;
    } while (iteration < 8);

    return 0;
}