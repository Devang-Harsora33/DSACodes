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
    struct Node *newNode, *temp, *lastnode;

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
        lastnode = newNode;
    }
    if (lastnode != NULL)
    {
        lastnode->next = start;
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
        while (temp->data != val && temp->next != start)
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
        while (temp->data != val && temp->next != start)
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
        pre->next = temp->next;
        free(temp);
    }
    else
    {
        while (temp->data != val && temp->next != start)
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
    while (temp->next != start)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d -> %d", temp->data, start->data);
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
        printf("6.Exit\n");
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
            exit(0);
            break;

        default:
            printf("Invalid Input!");
        }

        iteration++;
    } while (iteration < 8);

    return 0;
}