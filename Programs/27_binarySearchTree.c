#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int INFO;
    struct Node *LEFT;
    struct Node *RIGHT;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->INFO = value;
    newNode->LEFT = NULL;
    newNode->RIGHT = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value <= root->INFO)
    {
        root->LEFT = insert(root->LEFT, value);
    }
    else if (value >= root->INFO)
    {
        root->RIGHT = insert(root->RIGHT, value);
    }

    return root;
}

struct Node *inorderPredicator(struct Node *node)
{
    while (node->RIGHT != NULL)
    {
        node = node->RIGHT;
    }
    return node;
}

struct Node *inorderSuccessor(struct Node *node)
{
    while (node->LEFT != NULL)
    {
        node = node->LEFT;
    }
    return node;
}

/*
i) if the node being deleted has 0 child, then just delete it.
ii) if the node being deleted has 1 child, then just replace that node with it's one child.
iii) if the node being deleted has 2 child, then there's 2 condition.
      a) either replace that deleted node with it's inorder predicator (the largest element in it's
         left subtree)
      b) or replace it with it's inorder successor (the smallest element in it's right subtree)
         both are correct, implement both but use 1 of em & comment out the other one.
*/
struct Node *deleteNode(struct Node *root, int value)
{
    if (root == NULL)
    {
        return root;
    }

    if (value < root->INFO)
    {
        root->LEFT = deleteNode(root->LEFT, value);
    }
    else if (value > root->INFO)
    {
        root->RIGHT = deleteNode(root->RIGHT, value);
    }
    else
    {
        // Node with only one child or no child
        if (root->LEFT == NULL)
        {
            struct Node *temp = root->RIGHT;
            free(root);
            return temp;
        }
        else if (root->RIGHT == NULL)
        {
            struct Node *temp = root->LEFT;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node *temp = inorderPredicator(root->LEFT);
        root->INFO = temp->INFO;
        root->LEFT = deleteNode(root->LEFT, temp->INFO); // Delete the inorder predicator
    }
    return root;
}

void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->LEFT);
        printf("%d ", root->INFO);
        inorderTraversal(root->RIGHT);
    }
}

void preorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->INFO);
        preorderTraversal(root->LEFT);
        preorderTraversal(root->RIGHT);
    }
}

void postorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->LEFT);
        postorderTraversal(root->RIGHT);
        printf("%d ", root->INFO);
    }
}

int search(struct Node *root, int value)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->INFO == value)
    {
        return 1;
    }
    else if (value < root->INFO)
    {
        return search(root->LEFT, value);
    }
    else
    {
        return search(root->RIGHT, value);
    }
}

int main()
{
    struct Node *root = NULL;
    int n, value;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the values for the binary tree:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder traversal of the binary tree: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal of the binary tree: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal of the binary tree: ");
    postorderTraversal(root);
    printf("\n");

    int searchValue;
    printf("Enter a value to search for: ");
    scanf("%d", &searchValue);

    if (search(root, searchValue))
    {
        printf("%d found in the binary tree.\n", searchValue);
    }
    else
    {
        printf("%d not found in the binary tree.\n", searchValue);
    }

    printf("Enter the value to delete: ");
    scanf("%d", &value);
    root = deleteNode(root, value);

    printf("Inorder traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
