#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createNode(int data);
void insert(TreeNode **root, int data);
void printLevelOrder(TreeNode *root);
void printInorder(TreeNode *root);
void printPreorder(TreeNode *root);
void freeTree(TreeNode *root);
void printGraphical(TreeNode *root, int level, char branch);
void deleteNode(TreeNode **root, int data);

int main(void)
{
    TreeNode *root = NULL;
    int choice, data;

    while (1)
    {
        printf("1. Insert\n");
        printf("2. Print Level Order Traversal\n");
        printf("3. Print Inorder Traversal\n");
        printf("4. Print Preorder Traversal\n");
        printf("5. Exit\n");
        printf("6. Print Graphical Representation\n");
        printf("7. Delete a node\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            insert(&root, data);
            break;
        case 2:
            printf("Level Order Traversal: ");
            printLevelOrder(root);
            printf("\n");
            break;
        case 3:
            printf("Inorder Traversal: ");
            printInorder(root);
            printf("\n");
            break;
        case 4:
            printf("Preorder Traversal: ");
            printPreorder(root);
            printf("\n");
            break;
        case 5:
            freeTree(root);
            exit(0);
        case 6:
            printf("Graphical Representation:\n");
            printGraphical(root, 0, ' ');
            break;
        case 7:
            printf("Enter the data to delete: ");
            scanf("%d", &data);
            deleteNode(&root, data);
            break; 
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

TreeNode *createNode(int data)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(TreeNode **root, int data)
{
    if (*root == NULL)
    {
        *root = createNode(data);
        return;
    }
    if (data < (*root)->data)
        insert(&(*root)->left, data);
    else if (data > (*root)->data)
        insert(&(*root)->right, data);
}

void printLevelOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    TreeNode *queue[100];
    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        TreeNode *current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL)
        {
            queue[rear++] = current->left;
        }

        if (current->right != NULL)
        {
            queue[rear++] = current->right;
        }
    }
}

void printInorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

void printPreorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

void freeTree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

void printGraphical(TreeNode *root, int level, char branch)
{
    if (root == NULL)
        return;

    printGraphical(root->right, level + 1, '/');

    for (int i = 0; i < level; i++)
        printf("    ");

    printf("%c--%d\n", branch, root->data);

    printGraphical(root->left, level + 1, '\\');
}
void deleteNode(TreeNode **root, int data)
{
    if (*root == NULL)
    {
        return;
    }

    if (data < (*root)->data)
    {
        deleteNode(&(*root)->left, data);
    }
    else if (data > (*root)->data)
    {
        deleteNode(&(*root)->right, data);
    }
    else
    {
        if ((*root)->left == NULL && (*root)->right == NULL)
        {
            free(*root);
            *root = NULL;
        }
        else if ((*root)->left == NULL)
        {
            TreeNode *temp = *root;
            *root = (*root)->right;
            free(temp);
        }
        else if ((*root)->right == NULL)
        {
            TreeNode *temp = *root;
            *root = (*root)->left;
            free(temp);
        }
        else
        {
            TreeNode *temp = (*root)->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            (*root)->data = temp->data;
            deleteNode(&(*root)->right, temp->data);
        }
    }
}