#include <stdio.h>
int q[20], top = -1, front = -1, rear = -1, a[20][20], vis[20], stack[20];
int del();
void add(int item);
void bfs(int s, int n);
void dfs(int s, int n);
void push(int item);
int pop();
int main()
{
    int n = 7, i, s, ch, j;
    char c, dummy;
    a[0][0] = 0;
    a[0][1] = 1;
    a[0][2] = 1;
    a[0][3] = 1;
    a[0][4] = 0;
    a[0][5] = 0;
    a[0][6] = 0;
    a[0][7] = 0;

    a[1][0] = 1;
    a[1][1] = 0;
    a[1][2] = 0;
    a[1][3] = 0;
    a[1][4] = 1;
    a[1][5] = 0;
    a[1][6] = 0;
    a[1][7] = 1;

    a[2][0] = 1;
    a[2][1] = 0;
    a[2][2] = 0;
    a[2][3] = 0;
    a[2][4] = 1;
    a[2][5] = 0;
    a[2][6] = 0;
    a[2][7] = 0;

    a[3][0] = 1;
    a[3][1] = 0;
    a[3][2] = 0;
    a[3][3] = 0;
    a[3][4] = 0;
    a[3][5] = 1;
    a[3][6] = 0;
    a[3][7] = 0;

    a[4][0] = 0;
    a[4][1] = 1;
    a[4][2] = 1;
    a[4][3] = 0;
    a[4][4] = 0;
    a[4][5] = 0;
    a[4][6] = 1;
    a[4][7] = 0;

    a[5][0] = 0;
    a[5][1] = 0;
    a[5][2] = 0;
    a[5][3] = 1;
    a[5][4] = 0;
    a[5][5] = 0;
    a[5][6] = 1;
    a[5][7] = 0;

    a[6][0] = 0;
    a[6][1] = 0;
    a[6][2] = 0;
    a[6][3] = 0;
    a[6][4] = 1;
    a[6][5] = 1;
    a[6][6] = 0;
    a[6][7] = 1;

    a[7][0] = 0;
    a[7][1] = 1;
    a[7][2] = 0;
    a[7][3] = 0;
    a[7][4] = 0;
    a[7][5] = 0;
    a[7][6] = 1;
    a[7][7] = 0;

    printf("The Adjacency Matrix is: \n");
    for (i = 1; i <= 7; i++)
    {
        for (j = 1; j <= 7; j++)
        {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }

    do
    {
        for (i = 1; i <= n; i++)
            vis[i] = 0;
        printf("\nMenu");
        printf("\n1. B.F.S");
        printf("\n2. D.F.S");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        printf("Enter the source vertex: ");
        scanf("%d", &s);
        switch (ch)
        {
        case 1:
            bfs(s, n);
            break;
        case 2:
            dfs(s, n);
            break;
        }
        printf("\nDo u want to continue(y/n)? ");
        scanf("%c", &dummy);
        scanf("%c", &c);
    } while ((c == 'y') || (c == 'Y'));
}
void bfs(int s, int n)
{
    int p, i;
    add(s);
    vis[s] = 1;
    p = del();
    if (p != 0)
        printf(" %d", p);
    while (p != 0)
    {
        for (i = 1; i <= n; i++)
            if ((a[p][i] != 0) && (vis[i] == 0))
            {
                add(i);
                vis[i] = 1;
            }
        p = del();
        if (p != 0)
            printf("%d ", p);
    }
    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            bfs(i, n);

    return 0;
}
void add(int item)
{
    if (rear == 19)
        printf("Queue full..");
    else
    {
        if (rear == -1)
        {
            q[++rear] = item;
            front++;
        }
        else
            q[++rear] = item;
    }
}
int del()
{
    int k;
    if ((front > rear) || (front == -1))
        return (0);
    else
    {
        k = q[front++];
        return (k);
    }
}
void dfs(int s, int n)
{
    int i, k;
    push(s);
    vis[s] = 1;
    k = pop();
    if (k != 0)
        printf(" %d ", k);
    while (k != 0)
    {
        for (i = 1; i <= n; i++)
            if ((a[k][i] != 0) && (vis[i] == 0))
            {
                push(i);
                vis[i] = 1;
            }
        k = pop();
        if (k != 0)
            printf(" %d ", k);
    }
    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            dfs(i, n);
}
void push(int item)
{
    if (top == 19)
        printf("Stack overflow...");
    else
        stack[++top] = item;
}
int pop()
{
    int k;
    if (top == -1)
        return (0);
    else
    {
        k = stack[top--];
        return (k);
    }
}
