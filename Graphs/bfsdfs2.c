#include <stdio.h>
// graph is of numbers ranging from 0 - 7
int queue[20], top = -1, front = -1, rear = -1, vis[8], stack[20];
int a[9][9] = {
    {0, 1, 0, 1, 1, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 1, 0, 0},
    {1, 1, 0, 1, 0, 1, 1, 1, 0},
    {0, 0, 1, 0, 1, 0, 0, 1, 0},
    {0, 0, 0, 1, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 1, 1, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 1, 0},
};

void enqueue(int val)
{
    queue[++rear] = val;
}

int dequeue()
{
    return queue[++front];
}

void push(int val)
{
    stack[++top] = val;
}

int pop()
{
    return stack[top--];
}

void bfs(int s, int n)
{
    int i;
    enqueue(s);
    printf("%d ", s);
    vis[s] = 1;
    while (front <= rear)
    {
        int current = dequeue();
        if (!vis[current])
            printf("%d ", current);
        vis[current] = 1;
        for (i = 0; i < n; i++)
        {
            if (a[current][i] && !vis[i])
                enqueue(i);
        }
    }
}

void dfs(int s, int n)
{
    int i;
    push(s);
    printf("%d ", s);
    vis[s] = 1;
    while (top != -1)
    {
        int current = pop();
        if (!vis[current])
            printf("%d ", current);
        vis[current] = 1;
        for (i = 0; i < n; i++)
        {
            if (a[current][i] && !vis[i])
                push(i);
        }
    }
}

void reset(int n)
{
    front = rear = top = -1;
    for (int i = 0; i < n; i++)
        vis[i] = 0;
}

int main()
{
    int n = 9, i, s, j;

    printf("The Adjacency Matrix is: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }

    do
    {
        printf("\nMenu");
        printf("\n1. BFS");
        printf("\n2. DFS");
        printf("\n3. Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &i);
        printf("Enter the s vertex: ");
        scanf("%d", &s);
        switch (i)
        {
        case 1:
            bfs(s, n);
            reset(n);
            break;
        case 2:
            dfs(s, n);
            reset(n);
            break;
        case 3:
            return 0;
        }
    } while (i != 3);
    return 0;
}
