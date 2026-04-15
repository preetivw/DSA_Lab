#include <stdio.h>
#include <stdlib.h>

// Structure for Book
typedef struct book {
    int book_id;
    struct book *left, *right;
} BOOK;

// Function declarations
BOOK* insert(BOOK *root, int id);
BOOK* deleteBook(BOOK *root, int id);
BOOK* minValueNode(BOOK *node);
BOOK* search(BOOK *root, int id);
void inorder(BOOK *root);

// Create node
BOOK* createNode(int id) {
    BOOK *newnode = (BOOK*)malloc(sizeof(BOOK));
    newnode->book_id = id;
    newnode->left = newnode->right = NULL;
    return newnode;
}

// Insert
BOOK* insert(BOOK *root, int id) {
    if (root == NULL)
        return createNode(id);

    if (id < root->book_id)
        root->left = insert(root->left, id);
    else
        root->right = insert(root->right, id);

    return root;
}

// Search
BOOK* search(BOOK *root, int id) {
    if (root == NULL || root->book_id == id)
        return root;

    if (id < root->book_id)
        return search(root->left, id);
    else
        return search(root->right, id);
}

// Find minimum
BOOK* minValueNode(BOOK *node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// Delete
BOOK* deleteBook(BOOK *root, int id) {
    if (root == NULL) return root;

    if (id < root->book_id)
        root->left = deleteBook(root->left, id);
    else if (id > root->book_id)
        root->right = deleteBook(root->right, id);
    else {
        if (root->left == NULL) {
            BOOK *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            BOOK *temp = root->left;
            free(root);
            return temp;
        }

        BOOK *temp = minValueNode(root->right);
        root->book_id = temp->book_id;
        root->right = deleteBook(root->right, temp->book_id);
    }
    return root;
}

// Display (sorted)
void inorder(BOOK *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->book_id);
        inorder(root->right);
    }
}

// Main menu
int main() {
    BOOK *root = NULL;
    int choice, id;

    while (1) {
        printf("\n--- LIBRARY MENU ---\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Delete Book\n");
        printf("4. Display Books (Sorted)\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                root = insert(root, id);
                break;

            case 2:
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                if (search(root, id))
                    printf("Book Found\n");
                else
                    printf("Book Not Found\n");
                break;

            case 3:
                printf("Enter Book ID to delete: ");
                scanf("%d", &id);
                root = deleteBook(root, id);
                break;

            case 4:
                printf("Books in sorted order:\n");
                inorder(root);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
