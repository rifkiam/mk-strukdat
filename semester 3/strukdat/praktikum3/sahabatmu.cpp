// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

struct BSTNode{
    int key;
    BSTNode* left;
    BSTNode* right;
};

struct BST{
    BSTNode* root;
    unsigned int size;
};

void init(BST *BST) {
    BST->root = NULL;
    BST->size = 0u;
}

BSTNode* BSTCreateNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* BSTInsert(BSTNode *root, int value) {
    if (root == NULL) 
        return BSTCreateNode(value);

    if (value < root->key)
        root->left = BSTInsert(root->left, value);
    else if (value > root->key)
        root->right = BSTInsert(root->right, value);
    
    return root;
}

BSTNode* BSTFindMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

BSTNode* BSTDel(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = BSTDel(root->right, value);
    else if (value < root->key) 
        root->left = BSTDel(root->left, value);
    else {
        
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = BSTFindMinNode(root->right);
        root->key     = temp->key;
        root->right   = BSTDel(root->right, temp->key);
    }
    return root;
}

BSTNode* BSTSearch(BSTNode *root, int value) {
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

void insert(BST *BST, int value) {
    BST->root = BSTInsert(BST->root, value);
    BST->size++;
}

void del(BST *BST, int value) {
    BST->root = BSTDel(BST->root, value);
    BST->size--;
}

void changeRoot(BST *BST, int n){
    BST->root->key = n;
}

void BSTPreorder(BSTNode *root) {
    if (root) {
        cout << root->key << " ";
        BSTPreorder(root->left);
        BSTPreorder(root->right);
    }
}

void preorder(BST *BST) {
    BSTPreorder(BST->root);
}

int main() {
    int a = 0;
    BST set;
    init(&set);

    int t;
    cin >> t;

    int rt;
    cin >> rt;

    insert(&set, rt);

    t--;
    while(t--){
        int n;
        cin >> n;
        if(n > a && n < rt)
        {
            a = n;
        }
        insert(&set, n);
    }

    del(&set, a);
    changeRoot(&set, a);
    preorder(&set);

    return 0;
}