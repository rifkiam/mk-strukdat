#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node;

node* AVLTree(int dat);
int SubtreeHeight(node *nod);
int maxVal(int a, int b);
node *Lrotate(node *x);
node* Rrotate(node *y);
int getBalance(node *Nod);

node* insert(node* root,int val)
{
    if (root == NULL)
        return  AVLTree(val);

    if (val < root -> val)
        root->left = insert(root->left,val );
    else if (val > root->val)
        root->right = insert(root->right,val );


    root->ht = 1 + maxVal(SubtreeHeight(root->left), SubtreeHeight(root->right));

    //Get the balance factor of parent node
    int balance = getBalance(root);

    if (balance > 1 && val < root->left->val)
        return Rrotate(root);

    // Right Right Case
    if (balance < -1 && val > root->right->val)
        return Lrotate(root);

    // Left Right Case
    if (balance > 1 && val > root->left->val)
    {
        root->left = Lrotate(root->left);
        return Rrotate(root);
    }

    // Right Left Case
    if (balance < -1 && val < root->right->val)
    {
        root->right = Rrotate(root->right);
        return Lrotate(root);
    }
    return root;
}

node* Rrotate(node *y)
{
    node* x = y->left;
    node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->ht = maxVal(SubtreeHeight(y->left), SubtreeHeight(y->right)) + 1;
    x->ht = maxVal(SubtreeHeight(x->left), SubtreeHeight(x->right)) + 1;

    // Return new root
    return x;
}


node *Lrotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->ht = maxVal(SubtreeHeight(x->left), SubtreeHeight(x->right)) + 1;
    y->ht = maxVal(SubtreeHeight(y->left), SubtreeHeight(y->right)) + 1;

    // Return new root
    return y;
}

int getBalance(node *Nod)
{
    if (Nod == NULL)
        return 0;
    return SubtreeHeight(Nod->left) - SubtreeHeight(Nod->right);
}

int maxVal(int a,int b)
{
    return (a > b) ? a : b;
}

node* AVLTree(int dat)
{
    // Make new node 
    node* treeNode = (node*)malloc(sizeof(node));

    treeNode->val = dat;

    // init
    treeNode->left = NULL;
    treeNode->right = NULL;
    treeNode->ht = 0;
    return(treeNode);
}

int SubtreeHeight(node *nod)
{
    if (nod == NULL)
        return -1;
    return nod->ht;
}