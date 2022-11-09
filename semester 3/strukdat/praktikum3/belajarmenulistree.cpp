#include <iostream>
using namespace std;

struct bstNode{
    int key;
    bstNode* left;
    bstNode* right;
};

struct bst{
    bstNode* root;
    unsigned int size;
};

void init(bst *bst) {
    bst->root = NULL;
    bst->size = 0u;
}

bstNode* bstCreateNode(int value) {
    bstNode *newNode = (bstNode*) malloc(sizeof(bstNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bstNode* bstInsert(bstNode *root, int value) {
    if (root == NULL) 
        return bstCreateNode(value);

    if (value < root->key)
        root->left = bstInsert(root->left, value);
    else if (value > root->key)
        root->right = bstInsert(root->right, value);
    
    return root;
}

bstNode* bstSearch(bstNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}

void bstInorder(bstNode *root) {
    if (root) {
        bstInorder(root->left);
        printf("%d ", root->key);
        bstInorder(root->right);
    }
}

void bstPostorder(bstNode *root) {
    if (root) {
        bstPostorder(root->left);
        bstPostorder(root->right);
        printf("%d ", root->key);
    }
}

void insert(bst *bst, int value) {
    bst->root = bstInsert(bst->root, value);
    bst->size++;
}

void bstPreorder(bstNode *root) {
    if (root) {
        cout << root->key << " ";
        bstPreorder(root->left);
        bstPreorder(root->right);
    }
}

void preOrder(bst *bst) {
    bstPreorder(bst->root);
}

void inOrder(bst *bst) {
    bstInorder(bst->root);
}

void postOrder(bst *bst) {
    bstPostorder(bst->root);
}

int main() {
    int a = 0;
    bst tree;
    init(&tree);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        insert(&tree, n);
    }
    cout << "InOrder" << endl;
    inOrder(&tree);
    cout << "\nPreOrder\n";
    preOrder(&tree);
    cout << "\nPostOrder\n";
    postOrder(&tree);

    return 0;
}