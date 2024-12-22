#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createTree()
{
    int data;
    struct TreeNode *newNode;

    printf("Enter data (-1 for no child): ");
    scanf("%d", &data);

    if (data == -1)
    {
        return NULL;
    }

    newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;

    printf("Enter left child of %d:\n", data);
    newNode->left = createTree();

    printf("Enter right child of %d:\n", data);
    newNode->right = createTree();

    return newNode;
}

void inorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main()
{
    struct TreeNode *root;

    printf("Create Binary Tree:\n");
    root = createTree();

    printf("Inorder Traversal of the Binary Tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
