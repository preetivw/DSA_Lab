#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Insert into BST
struct Node* insert(struct Node* root, int key) {
    if (root == NULL)
        return newNode(key);

    if (key < root->val)
        root->left = insert(root->left, key);
    else if (key > root->val)
        root->right = insert(root->right, key);

    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

int main() {
    int n;

    scanf("%d", &n);

    // Check invalid input
    if (n == -1) {
        printf("Invalid input");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int insertVal;
    scanf("%d", &insertVal);

    if (insertVal == -1) {
        printf("Invalid input");
        return 0;
    }

    struct Node* root = NULL;

    // Build BST
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    // Insert new router ID
    root = insert(root, insertVal);

    // Output inorder traversal
    inorder(root);

    return 0;
}
