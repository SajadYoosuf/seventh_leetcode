#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (root == NULL)
        return createNode(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else if (val > root->val)
        root->right = insertBST(root->right, val);
    return root;
}

// Function to search in BST
TreeNode* searchBST(TreeNode* root, int key) {
    if (root == NULL || root->val == key)
        return root;
    if (root->val > key)
        return searchBST(root->left, key);
    return searchBST(root->right, key);
}

// Function to print BST in level-order (BFS)
void printLevelOrder(TreeNode* root) {
    if (root == NULL) {
        printf("[]\n");
        return;
    }
    
    TreeNode* queue[5000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    printf("[");
    while (front < rear) {
        TreeNode* current = queue[front++];
        printf("%d", current->val);
        if (front < rear || current->left || current->right) {
            printf(",");
        }
        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
    printf("]\n");
}

// Main function to test the search function
int main() {
    TreeNode* root = NULL;
    int n, val, key;
    
    printf("Enter the number of elements to insert in BST: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insertBST(root, val);
    }
    
    printf("Enter the key to search: ");
    scanf("%d", &key);
    
    TreeNode* result = searchBST(root, key);
    
    printLevelOrder(result);
    
    return 0;
}
