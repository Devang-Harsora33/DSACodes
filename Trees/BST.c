#include <stdio.h>
#include <stdlib.h>
// delete k baad insert not working but operation runs when same code run on online compiler
struct node
{
    int data;
    struct node *left, *right;
} *root;

void create()
{
    int i, number, data;
    struct node *newNode, *temp, *parent;
    printf("Enter the number of nodes: ");
    scanf("%d", &number);
    for (i = 0; i < number; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &data);
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        parent = temp = root;
        if (!root)
            root = newNode;
        else
        {
            while (temp)
            {
                parent = temp;
                if (temp->data > data)
                    temp = temp->left;
                else
                    temp = temp->right;
            }
            if (parent->data > data)
                parent->left = newNode;
            else
                parent->right = newNode;
        }
    }
}
void insert()
{
    struct node *newNode, *temp, *parent;
    int val;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the value of the node:\n");
    scanf("%d", &val);
    newNode->data = val;
    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        temp = root;
        while (temp != NULL)
        {
            parent = temp;
            if (temp->data <= val)
            {
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }
        if (parent->data <= val)
            parent->right = newNode;
        else
            parent->left = newNode;
    }
}
void delete()
{
    int val;
    struct node *temp, *parent, *ps, *succ;
    printf("Enter the value to be deleted:\n");
    scanf("%d", &val);
    temp = root;
    while (temp != NULL && temp->data != val)
    {
        parent = temp;
        if (temp->data <= val)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
    if (temp == NULL)
    {
        printf("Value not Found!");
    }
    else if (temp->right == NULL && temp->left == NULL)
    {
        if (parent->left == temp)
        {
            parent->left = NULL;
            free(temp);
        }
        else
        {
            parent->right = NULL;
            free(temp);
        }
    }
    else if (temp->left != NULL)
    {
        if (parent->left == temp)
        {
            parent->left = temp->left;
            free(temp);
        }
        else
        {
            parent->right = temp->left;
            free(temp);
        }
    }
    else if (temp->right != NULL)
    {
        if (parent->left == temp)
        {
            parent->left = temp->right;
            free(temp);
        }
        else
        {
            parent->right = temp->right;
            free(temp);
        }
    }
    else // deleting a parentent with two children !!DOUBT !!
    {
        succ = temp->left;
        ps = temp;
        while (succ->right != NULL)
        {
            ps = succ;
            succ = succ->right;
        }
        if (ps == temp)
        {
            temp->data = succ->data;
            temp->left = NULL;
            free(succ);
        }
        else
        {
            temp->data = succ->data;
            ps->right = succ->left;
            free(succ);
        }
    }
}
void inorder(struct node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%d", temp->data);
        inorder(temp->right);
    }
}
void preorder(struct node *temp)
{
    if (temp != NULL)
    {
        printf("%d", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}
void postorder(struct node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d", temp->data);
    }
}

int main()
{
    int choice;
    create();
    do
    {
        printf("\n1.insert \n2.delete \n3.display using inorder\n4.display using preorder \n5.display using postorder\n6.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            insert();
            break;
        }
        case 2:
        {
            delete ();
            break;
        }
        case 3:
        {
            inorder(root);
            break;
        }
        case 4:
        {
            preorder(root);
            break;
        }
        case 5:
        {
            postorder(root);
            break;
        }
        case 6:
        {
            exit(0);
        }
        default:
        {
            printf("Invalid input!");
            break;
        }
        }

    } while (choice != 6);
    return 0;
}