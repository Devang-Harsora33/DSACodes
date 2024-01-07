#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node
{
    int data;
    struct Node *next;
};

struct Node *hashTable[SIZE] = {NULL};

// Hash function to map values to an index in the hash table
int hashFunction(int key)
{
    return key % SIZE;
}

// Function to insert a value into the hash table
void insert(int key)
{
    int index = hashFunction(key);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;

    // If the bucket is empty
    if (hashTable[index] == NULL)
    {
        hashTable[index] = newNode;
    }
    else
    {
        // Collision handling: Insert at the beginning of the linked list
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

// Function to search for a value in the hash table
struct Node *search(int key)
{
    int index = hashFunction(key);
    struct Node *current = hashTable[index];

    while (current != NULL)
    {
        if (current->data == key)
        {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

// Function to delete a value from the hash table
void delete(int key)
{
    int index = hashFunction(key);
    struct Node *current = hashTable[index];
    struct Node *prev = NULL;

    while (current != NULL)
    {
        if (current->data == key)
        {
            if (prev == NULL)
            {
                // If the node to be deleted is the first node in the list
                hashTable[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }

            free(current);
            return;
        }

        prev = current;
        current = current->next;
    }
}

// Function to display the hash table
void display()
{
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d: ", i);
        struct Node *current = hashTable[i];
        while (current != NULL)
        {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int choice, key;
    do
    {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n0. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the key to insert: ");
            scanf("%d", &key);
            insert(key);
            break;
        case 2:
            printf("Enter the key to search: ");
            scanf("%d", &key);
            if (search(key) != NULL)
                printf("Key %d found in the hash table.\n", key);
            else
                printf("Key %d not found in the hash table.\n", key);
            break;
        case 3:
            printf("Enter the key to delete: ");
            scanf("%d", &key);
            delete(key);
            break;
        case 4:
            display();
            break;
        case 0:
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
