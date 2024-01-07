#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define SIZE 10
int key = -1;
int h[SIZE] = {0};

int linear(int a, int i)
{
    return ((a + i) % SIZE);
}

int quad(int coefficient, int constant, int key, int i)
{
    int function_ans = (coefficient * key) + constant;
    return ((function_ans + i * i) % SIZE);
}

int insert()
{
    int opt;
    while (1)
    {
        printf("\nMenu:\n1.Linear Hash\n2.Quadratic Hash\n3.BACK\n");
        printf("Enter your hashing choice:\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
        {
            linear_hash();
            break;
        }
        case 2:
        {
            quadratic_hash();
            break;
        }
        case 3:
        {
            return 0;
        }
        default:
        {
            printf("Wrong choice , enter again.\n");
        }
        }
    }
}

int search()
{
    int opt;
    while (1)
    {
        printf("\nMenu:\n1.Linear Hash\n2.Quadratic Hash\n3.BACK \n");
        printf("Enter your searching choice:\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
        {
            linear_search();
            break;
        }
        case 2:
        {
            quadratic_search();
            break;
        }
        case 3:
        {
            return 0;
        }
        default:
        {
            printf("Wrong choice , enter again.\n");
        }
        }
    }
}

int linear_hash()
{
    int i = 0;
    int index = -1;
    int key = -1;
    printf("Enter value:\n");
    scanf("%d", &key);
    for (i = 0; i < SIZE; i++)
    {
        index = linear(key, i);

        if (h[index] == 0)
        {
            h[index] = key;
            printf("Value %d inserted at index %d\n", key, index);
            return 0;
        }
    }
    if (i == SIZE)
    {
        printf("Hash is full , value could not be inserted\n");
    }
    return 0;
}

int linear_search()
{
    int i = 0, index = -1, key = -1;

    printf("Enter value:\n");
    scanf("%d", &key);
    for (; i < SIZE; i++)
    {
        index = linear(key, i);

        if (h[index] == key)
        {
            printf("Value %d found at index %d\n", key, index);
            return 0;
        }
    }

    if (i == SIZE)
    {
        printf("Value not found.\n");
    }
    return 0;
}

int quadratic_hash()
{
    int coefficient = 0, constant = 0, i = 0, key = -1, index = -1;
    printf("Enter value:\n");
    scanf("%d", &key);
    printf("Enter a function in the form of a linear equation i.e. {coefficient}x+{constant}\nEnter coefficient: ");
    scanf("%d", &coefficient);
    printf("Enter constant: ");
    scanf("%d", &constant);
    printf("\n");
    for (i = 0; i < SIZE; i++)
    {
        index = quad(coefficient, constant, key, i);
        if (h[index] == 0)
        {
            h[index] = key;
            printf("Value %d inserted at index %d\n", key, index);
            return 0;
        }
    }
    if (i == SIZE)
    {
        printf("Hash is full , value could not be inserted\n");
    }
    return 0;
}

int quadratic_search()
{
    int coefficient = 0, constant = 0, i = 0, key = -1, index = -1;

    printf("Enter a function in the form of a linear equation i.e. {coefficient}x+{constant}\nEnter coefficient: ");
    scanf("%d", &coefficient);
    printf("Enter constant: ");
    scanf("%d", &constant);
    printf("\n");
    printf("Enter value :\n");
    scanf("%d", &key);
    printf("\n");
    for (i = 0; i < SIZE; i++)
    {
        index = quad(coefficient, constant, key, i);
        if (h[index] == key)
        {
            printf("Value %d is found at index %d\n", key, index);
            return 0;
        }
    }
    if (i == SIZE)
    {
        printf("Value not found.\n");
    }
    return 0;
}

void display()
{
    int i;
    printf("\nElements are \n");
    for (i = 0; i < SIZE; i++)
    {
        printf("\nIndex %d value =  %d", i, h[i]);
    }
}

int main()
{
    int opt;
    while (1)
    {
        printf("\nMenu:\n1.Insert\n2.Search\n3.Display\n4.Exit\n");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            insert();
            break;
        case 2:
            search();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(EXIT_FAILURE);
        default:
            printf("Invalid choice try again");
        }
    }
    return 0;
}
