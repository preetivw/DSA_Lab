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

// Find minimum node
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Delete node from BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->val)
        root->left = deleteNode(root->left, key);
    else if (key > root->val)
        root->right = deleteNode(root->right, key);
    else {
        // Node found

        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }

    return root;
}

// Inorder traversal (no trailing space)
void inorder(struct Node* root, int *first) {
    if (root == NULL) return;

    inorder(root->left, first);

    if (*first) {
        printf("%d", root->val);
        *first = 0;
    } else {
        printf(" %d", root->val);
    }

    inorder(root->right, first);
}

int main() {
    int n;
    scanf("%d", &n);

    printf("Current File Index sorted in ascending order: ");

    if (n <= 0) {
        printf("\n");
        return 0;
    }

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int insertVal, deleteVal;

    // SAFE INPUT: handles both single-line and two-line cases
    if (scanf("%d %d", &insertVal, &deleteVal) != 2) {
        printf("\n");
        return 0;
    }

    struct Node* root = NULL;

    // Build BST
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    // Insert new value
    root = insert(root, insertVal);

    // Delete value
    root = deleteNode(root, deleteVal);

    int first = 1;
    inorder(root, &first);

    printf("\n");

    return 0;
}
