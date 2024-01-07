#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *prev, *next;
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
            newNode->prev = NULL;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}

void insert_before(int val, int data)
{
    struct Node *newNode, *temp, *p;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    temp = start;
    while (temp->data != val)
    {
        p = temp;
        temp = temp->next;
    }
    if (temp->data == val)
    {
        if (temp == start)
        {
            newNode->next = start;
            start->prev = newNode;
            start = newNode;
        }
        else
        {
            while (temp->data != val)
            {
                p = temp;
                temp = temp->next;
            }
            p->next = newNode;
            newNode->prev = p;
            newNode->next = temp;
            temp->prev = newNode;
        }
    }

    else
        printf("Value not found !");
}

void insert_after(int val, int data)
{
    struct Node *newNode, *temp, *post;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    temp = start;
    while (temp->data != val)
    {
        temp = temp->next;
    }
    post = temp->next;
    if (temp->data == val)
    {
        newNode->prev = temp;
        temp->next = newNode;

        if (post != NULL)
        {
            post->prev = newNode;
            newNode->next = post;
        }
    }

    else
        printf("Value not found !");
}

void del(int val)
{

    struct Node *temp, *p, *post;
    temp = start;
    while (temp->data != val && temp->next != NULL)
    {
        p = temp;
        temp = temp->next;
    }
    post = temp->next;
    if (temp->data == val)
    {
        if (temp == start)
        {
            start = temp->next;
            free(temp);
        }
        else
        {
            p->next = post;
            post->prev = p;
            free(temp);
        }
    }

    else
        printf("Value not found !");
}

void display()
{
    struct Node *temp;
    temp = start;
    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            printf("%d <--> ", temp->data);
        }
        else
        {
            printf("%d", temp->data);
        }
        temp = temp->next;
    }
}
void searchElement(int val)
{
    struct Node *temp = start;
    int index = 0;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            printf("Value %d found at index %d.\n", val, index);
            return;
        }
        temp = temp->next;
        index++;
    }

    printf("Value %d not found in the list.\n", val);
}

int main()
{
    int i, iteration = 0;
    int val;
    int data;
    create();
    do
    {
        printf("\nMenu:\n");
        printf("1.Insert Before\n");
        printf("2.Insert After\n");
        printf("3.Delete\n");
        printf("4.Display\n");
        printf("5.Display\n");
        printf("6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("Enter data before which node is to be inserted: ");
            scanf("%d", &val);
            printf("Enter data:");
            scanf("%d", &data);
            insert_before(val, data);
            break;

        case 2:
            printf("Enter data after which node is to be inserted: ");
            scanf("%d", &val);
            printf("Enter data:");
            scanf("%d", &data);
            insert_after(val, data);
            break;

        case 3:
            printf("Enter the element to be deleted: ");
            scanf("%d", &val);
            del(val);
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Enter the element to be searched: ");
            scanf("%d", &val);
            searchElement(val);
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
