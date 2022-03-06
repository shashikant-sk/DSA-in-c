// Extend the LA 1 by providing more options as follows:
// a) To count number of leaf nodes in the tree.
// b) To count number of non-leaf nodes in the tree.
// c) To find number of nodes in the tree.
// d) To find sum of all nodes of the tree.
// e) To print depth of the tree.
// f) To find nodes which are at maximum depth in the tree?
// g) To print all the elements of kth level in single line.
// h) To find lowest the common ancestor.
// i) To check whether a tree is a binary search tree or not.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct BST
{
    int data;
    struct BST *left, *right;
} BST;

void insertBST(BST **root, int data)
{
    BST *newNode = (BST *)malloc(sizeof(BST));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    if (!(*root))
        *root = newNode;
    else
    {
        BST *prev = NULL, *tmp = *root;
        while (tmp)
        {
            prev = tmp;
            if (tmp->data > data)
                tmp = tmp->left;
            else if (tmp->data < data)
                tmp = tmp->right;
        }
        if (prev->data > data)
            prev->left = newNode;
        else
            prev->right = newNode;
    }
}

void createBST(BST **root)
{
    int choice = 1;
    do
    {
        int data = 0;
        printf("\nEnter a number to enter in BST: ");
        scanf("%d", &data);
        insertBST(root, data);
        printf("\nPress 1 to enter a value to BST or 0 to exit: ");
        scanf("%d", &choice);
    } while (choice == 1);
}

void Inorder(BST *root)
{
    if (!root)
        return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

void Preorder(BST *root)
{
    if (!root)
        return;
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(BST *root)
{
    if (!root)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
}

void search(BST *root, int data)
{
    BST *tmp = root;
    while (tmp)
    {
        if (tmp->data > data)
            tmp = tmp->left;
        else if (tmp->data < data)
            tmp = tmp->right;
        else
        {
            printf("\n%d found in BST!\n", data);
            return;
        }
    }
    printf("\nElement not found in BST!\n");
}

void findSmallest(BST *root)
{
    if (root == NULL)
        printf("\nBST EMPTY!\n");
    else
    {
        BST *tmp = root;
        while (tmp->left)
            tmp = tmp->left;
        printf("\nSmallest element in BST = %d\n", tmp->data);
    }
}

void findLargest(BST *root)
{
    if (root == NULL)
        printf("\nBST EMPTY!\n");
    else
    {
        BST *tmp = root;
        while (tmp->right)
            tmp = tmp->right;
        printf("\nLargest element in BST = %d\n", tmp->data);
    }
}

void _deleteTree(BST *root)
{
    if (root == NULL)
        return;
    _deleteTree(root->left);
    _deleteTree(root->right);
    free(root);
}

void deleteTree(BST **root)
{
    _deleteTree(*root);
    *root = NULL;
}

int countLeaf(BST *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

int countNodes(BST *root)
{
    if (!root)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int countNonLeafNodes(BST *root)
{
    return countNodes(root) - countLeaf(root);
}

int sumOfNodes(BST *root)
{
    if (!root)
        return 0;
    return root->data + sumOfNodes(root->right) + sumOfNodes(root->left);
}

int maxDepth(BST *root)
{
    if (!root)
        return 0;
    else
    {
        int ldep = maxDepth(root->left);
        int rdep = maxDepth(root->right);
        if (ldep > rdep)
            return ldep + 1;
        else
            return rdep + 1;
    }
}

void printCurrentLevel(BST *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printLevelOrder(BST *root)
{
    int h = maxDepth(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

int isBSTUtil(BST *root, int min, int max)
{
    if (root == NULL)
        return 1;

    if (root->data < min || root->data > max)
        return 0;

    return isBSTUtil(root->left, min, root->data - 1) && isBSTUtil(root->right, root->data + 1, max);
}

BST *findLCA(BST *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;

    BST *left_lca = findLCA(root->left, n1, n2);
    BST *right_lca = findLCA(root->right, n1, n2);

    if (left_lca && right_lca)
        return root;

    return (left_lca != NULL) ? left_lca : right_lca;
}

int main()
{
    BST *root = NULL;
    while (1)
    {
        int choice;
        printf("\n----------------------------------------\n"
               "\tBinary Search Tree Menu\n"
               "----------------------------------------\n"
               "0. Quit\n"
               "1. Create\n"
               "2. In-Order Traversal\n"
               "3. Pre-Order Traversal\n"
               "4. Post-Order traversal\n"
               "5. Search\n"
               "6. Find Smallest Element\n"
               "7. Find Largest Element\n"
               "8. Deletion of Tree\n"
               "9. To count number of leaf nodes in the tree.\n"
               "10. To count number of non-leaf nodes in the tree.\n"
               "11. To find number of nodes in the tree.\n"
               "12. To find sum of all nodes of the tree.\n"
               "13. To print depth of the tree.\n"
               "14. To find nodes which are at maximum depth in the tree?\n"
               "15. To print all the elements of kth level in single line.\n"
               "16. To find the lowest common ancestor.\n"
               "17. To check whether a tree is a binary search tree or not.\n"
               "----------------------------------------\n"
               "Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            return 0;
            break;
        case 1:
            createBST(&root);
            break;
        case 2:
            if (root == NULL)
            {
                printf("\nBST EMPTY!\n");
                break;
            }
            printf("In-order traversal: ");
            Inorder(root);
            printf("\n");
            break;
        case 3:
            if (root == NULL)
            {
                printf("\nBST EMPTY!\n");
                break;
            }
            printf("Pre-order traversal: ");
            Preorder(root);
            printf("\n");
            break;
        case 4:
            if (root == NULL)
            {
                printf("\nBST EMPTY!\n");
                break;
            }
            printf("Post-order traversal: ");
            Postorder(root);
            printf("\n");
            break;
        case 5:
        {
            int d;
            printf("Enter number to search: ");
            scanf("%d", &d);
            search(root, d);
        }
        break;
        case 6:
            findSmallest(root);
            break;
        case 7:
            findLargest(root);
            break;
        case 8:
            deleteTree(&root);
            break;
        case 9:
            printf("\nNumber of leaf nodes = %d\n", countLeaf(root));
            break;
        case 10:
            printf("\nNumber of non-leaf nodes = %d\n", countNonLeafNodes(root));
            break;
        case 11:
            printf("\nNumber of nodes = %d\n", countNodes(root));
            break;
        case 12:
            printf("\nSum of data of all nodes = %d\n", sumOfNodes(root));
            break;
        case 13:
            printf("\nDepth of BST = %d\n", maxDepth(root));
            break;
        case 14:
            printf("\nNodes at max depth -> ");
            printCurrentLevel(root, maxDepth(root));
            printf("\n");
            break;
        case 15:
        {
            int k;
            printf("Enter k(starts from 1): ");
            scanf("%d", &k);
            printf("\nNodes at k = %d depth -> ", k);
            printCurrentLevel(root, k);
            printf("\n");
        }
        break;
        case 16:
        {
            int n1, n2;
            printf("Enter 2 node values to find common ancestor: ");
            scanf("%d %d", &n1, &n2);
            BST *temp = findLCA(root, n1, n2);
            temp == NULL ? printf("\nAtleast one node doesn't exist in the tree.\n") : printf("\nThe common ancestor -> %d\n", temp->data);
        }
        break;
        case 17:
            isBSTUtil(root, INT_MIN, INT_MAX) ? printf("\nThe tree is a BST!\n") : printf("\nThe tree is not a BST!\n");
            break;
        default:
            printf("\nEnter a valid choice!\n");
            break;
        }
    }
    return 0;
}
