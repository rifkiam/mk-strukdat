#include <iostream>
using namespace std;

struct treeNode {
    treeNode *left, *right;
    string nama;
};

struct BST {
    treeNode *root;
    unsigned _size;
};

treeNode* __preorderSearch(treeNode *r, string nama);

void init(BST *tree) {
    tree->root = NULL;
    tree->_size = 0u;
}

bool isEmpty(BST *tree) {
    return tree->root == NULL;
}

// bool find(BST tree, string value) {
//     treeNode *temp = __search(tree.root, value);
//     if (!temp)
//         return false;
    
//     if (temp->nama == value)
//     {
//         return true;
//     }
//     else
//     {
//         cout << "No such data in tree";
//         return false;
//     }
// }

// treeNode* __search(treeNode *root, string value) {
//     while (root != NULL) {
//         if (value < root->nama)
//             root = root->left;
//         else if (value > root->nama)
//             root = root->right;
//         else
//             return root;
//     }
//     return root;
// }

// void traverseInorder(BST *tree) {
//     __inorderSearch(root);
// }

void traversePreorder(BST *tree, string nama) {
    treeNode* r = tree->root;
    __preorderSearch(r, nama);
}

// void traversePostorder(BST *tree) {
//     __postorderSearch(root);
// }


void __preorderSearch(treeNode *r, string nama) {
    if(r->nama == nama)
    {
        cout <<  r->nama;
    }
    else
    {
        // printf("%s ", root->nama);
        cout << r->nama;
        __preorderSearch(r->left, nama);
        __preorderSearch(r->right, nama);
    }
}


// void insert(string value) {
//     if (!find(value)) {
//         _root = __insert(_root, value);
//         _size++;
//     }
//         _root = __insert(_root, value);
//         _size++;
// }

// void remove(string value) {
//     if (find(value)) {
//         _root = __remove(_root, value);
//         _size--;
//     }
// }

treeNode* __createNode(string value) {
    treeNode *newNode = (treeNode*) malloc(sizeof(treeNode));
    newNode->nama = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    BST familyTree;
    init(&familyTree);
    familyTree.root = __createNode("Leluhur");
    familyTree.root->left = __createNode("Saudara"), familyTree.root->right = __createNode("Lin");
    // traversePreorder(&familyTree, "Lin");
    cout << familyTree.root->nama;
    return 0;
}

//     binarytree._root->nama = "Leluhur"; //root
//     binarytree._root->left->nama = "Saudara", binarytree._root->right->nama = "Lin"; //depth = 1
//     binarytree._root->right->left->nama = "Sulkan", binarytree._root->right->right->nama = "Suti"; //depth = 2
//     binarytree._root->right->right->left->nama = "Harimi", binarytree._root->right->right->right->nama = "Darwin"; //depth = 3
//     binarytree._root->right->right->left->left->nama = "Alvia", binarytree._root->right->right->left->right->nama = "Nurul"; /*Pembatas*/ binarytree._root->right->right->right->left->nama = "Yan", binarytree._root->right->right->right->right->nama = "Sani"; //depth = 4
//     binarytree._root->right->right->left->left->left->nama = "Faris", binarytree._root->right->right->left->left->right->nama = "Nisa"; /*Pembatas*/ binarytree._root->right->right->left->right->left->nama = "Nadiah", binarytree._root->right->right->left->right->right->nama = "Rifqi"; /*Pembatas*/ binarytree._root->right->right->right->right->left->nama = "Dilla"; //depth = 5