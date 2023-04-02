#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Node** tree, int data) {
    if (*tree == NULL) {
        *tree = newNode(data);
        return;
    }
    insert(&(*tree)->left, data);
    insert(&(*tree)->right, data);
}

void allNodes(Node* tree) {
    if (tree == NULL) {
        return;
    }
    allNodes(tree->left);
    printf("%d\n", tree->data);
    allNodes(tree->right);
}

void freeNodes(Node** tree) {
    if (*tree == NULL) {
        return;
    }
    freeNodes(&(*tree)->left);
    freeNodes(&(*tree)->right);
    free(*tree);
}

bool searchNode(Node* tree, int key) {
    if (tree == NULL) {
        return false;
    }
    if (tree->data == key) {
        return true;
    }
    searchNode(tree->left, key);
    searchNode(tree->right, key);
}

// Test code
int main() {
    Node* root = NULL;
    insert(&root, 23);
    insert(&root, 12);
    insert(&root, 14);
    allNodes(root);
    printf("%d\n", (int) searchNode(root, 23));
    printf("%d\n", (int) searchNode(root, 8));
    freeNodes(&root);
    return 0;
}
