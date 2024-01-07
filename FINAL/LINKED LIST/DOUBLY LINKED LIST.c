#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Function to delete a node with a given value
void deleteNode(struct Node **head, int key)
{
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node *current = *head;

    // Search for the node to be deleted
    while (current != NULL && current->data != key)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Node with value %d not found\n", key);
        return;
    }

    // Adjust pointers to skip the node to be deleted
    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }
    else
    {
        *head = current->next;
    }

    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }

    free(current);
}
void insertAtAnyNode(struct Node **head, int data, int position)
{
    struct Node *newNode = createNode(data);

    if (*head == NULL || position <= 1)
    {
        insertAtBeginning(head, data);
    }
    else
    {
        struct Node *temp = *head;
        int currentPosition = 1;

        while (temp->next != NULL && currentPosition < position - 1)
        {
            temp = temp->next;
            currentPosition++;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}
// Function to display the doubly linked list
void display(struct Node *head)
{
    struct Node *temp = head;

    printf("NULL<->");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
}

// Main function
int main()
{
    struct Node *head = NULL;
    int choice, data, position;

    do
    {
        printf("\nDoubly Linked List Menu\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at any node\n");
        printf("3. Insert at the end\n");
        printf("4. Delete a node\n");
        printf("5. Display the list\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at the beginning: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position to insert at: ");
            scanf("%d", &position);
            insertAtAnyNode(&head, data, position);
            break;

        case 3:
            printf("Enter data to insert at the end: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;

        case 4:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            deleteNode(&head, data);
            break;

        case 5:
            printf("Doubly Linked List: ");
            display(head);
            break;

        case 0:
            printf("Exiting the program\n");
            break;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 0);

    return 0;
}
