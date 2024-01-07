#include <stdio.h>
#define SIZE 10
int hash(int val)
{
    int index = val % SIZE;
    return index;
}
int probe(int HT[], int val)
{
    int i = 0;
    int index = hash(val);
    if (HT[index] != 0)
    {
        while (HT[(index + i) % SIZE] != 0)
        {
            i++;
        }
    }
    return (index + i) % SIZE;
}

void insert(int HT[], int val)
{
    int index = hash(val);
    if (HT[index] != 0)
    {
        index = probe(HT, val);
    }
    HT[index] = val;
}
void search(int HT[], int val)
{
    int i = 0;
    int index = hash(val);
    if (HT[index] != val)
    {
        while (HT[(index + i) % SIZE] != val)
        {
            i++;
        }
    }
    return (index + i) % SIZE;
}