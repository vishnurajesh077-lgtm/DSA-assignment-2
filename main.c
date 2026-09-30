#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    char id[10];
    struct Node *left;
    struct Node *right;
} Node;


Node* createNode(const char *id) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->id, id);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


Node* insertBST(Node *root, const char *id) {
    if (root == NULL) {
        return createNode(id);
    }
    if (strcmp(id, root->id) < 0) {
        root->left = insertBST(root->left, id);
    } else if (strcmp(id, root->id) > 0) {
        root->right = insertBST(root->right, id);
    }
    return root;
}


void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s ", root->id);
        inorderTraversal(root->right);
    }
}


int searchBST(Node *root, const char *key, int *comparisons) {
    if (root == NULL) {
        return 0; // Not found
    }
    
    (*comparisons)++;
    int cmp = strcmp(key, root->id);
    
    if (cmp == 0) {
        return 1; // Found
    } else if (cmp < 0) {
        return searchBST(root->left, key, comparisons);
    } else {
        return searchBST(root->right, key, comparisons);
    }
}


int linearSearch(char arr[][10], int n, const char *key, int *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < n; i++) {
        (*comparisons)++;
        if (strcmp(arr[i], key) == 0) {
            return 1; // Found
        }
    }
    return 0; // Not found
}


int main() {
    char ids[8][10] = {"A102", "A25", "A7", "B100", "B12", "A120", "B3", "A45"};
    int n = 8;
    Node *root = NULL;

    printf("=== GOVERNMENT DATABASE IDENTIFICATION SEARCH SYSTEM ===\n\n");

    
    printf("1. Inserting Identification Numbers into BST:\n");
    for (int i = 0; i < n; i++) {
        root = insertBST(root, ids[i]);
        printf("Inserted: %s\n", ids[i]);
    }

    
    printf("\n2. Inorder Traversal (Sorted Identification Numbers):\n");
    inorderTraversal(root);
    printf("\n\n");

    
    char targetKeys[3][10] = {"A120", "B3", "A999"}; // Existing & Non-existing
    printf("3. Search Performance Comparison:\n");
    printf("-------------------------------------------------------------------\n");
    printf("| Target ID | BST Found? | BST Comparisons | Linear Search Comp | \n");
    printf("-------------------------------------------------------------------\n");

    for (int i = 0; i < 3; i++) {
        int bstComp = 0;
        int linComp = 0;
        
        int bstResult = searchBST(root, targetKeys[i], &bstComp);
        int linResult = linearSearch(ids, n, targetKeys[i], &linComp);

        printf("| %-9s | %-10s | %-15d | %-18d |\n", 
               targetKeys[i], 
               bstResult ? "YES" : "NO", 
               bstComp, 
               linComp);
    }
    printf("-------------------------------------------------------------------\n");

    return 0;
}
