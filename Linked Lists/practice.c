#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *start1, *start2;

struct Node *create()
{
    int no_of_nodes, i, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &no_of_nodes);
    struct Node *newNode, *temp, *start = NULL;

    for (i = 0; i < no_of_nodes; i++)
    {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("\nEnter the node value :");
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
    return start;
}
void display(struct Node *temp)
{
    while (temp != NULL)
    {
        if (temp->next != NULL)
        {
            printf("%d ->", temp->data);
        }
        else
        {
            printf("%d ", temp->data);
        }
        temp = temp->next;
    }
    printf("\n");
}
struct Node *merge()
{

    struct Node *temp = NULL;
    temp = start1;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = start2;

    return start1;
}

int main()
{
    printf("Enter the list1 data:\n");
    start1 = create();
    printf("Enter the list2 data:\n");
    start2 = create();
    printf("\nList1:");
    display(start1);
    printf("\nList2:");
    display(start2);
    start1 = merge();
    printf("\nMerged List is :\n");
    display(start1);
}
