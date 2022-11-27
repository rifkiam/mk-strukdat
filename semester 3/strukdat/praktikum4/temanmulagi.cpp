#include <bits/stdc++.h>
using namespace std;

// int found = 0;
int column = 0;
int columnValues[10001];

struct AVLNode
{
    int data;
    AVLNode *left, *right;
    int height;
};

AVLNode *leftmostptr;

struct AVL
{
private:
    AVLNode *_root;
    unsigned _size;

    AVLNode *_avl_createNode(int value)
    {
        AVLNode *newNode = (AVLNode *)malloc(sizeof(AVLNode));
        newNode->data = value;
        newNode->height = 1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    AVLNode *_search(AVLNode *root, int value)
    {
        while (root != NULL)
        {
            if (value < root->data)
                root = root->left;
            else if (value > root->data)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    int _getHeight(AVLNode *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int _max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    AVLNode *_rightRotate(AVLNode *pivotNode)
    {
        AVLNode *newParrent = pivotNode->left;
        pivotNode->left = newParrent->right;
        newParrent->right = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left),
                                 _getHeight(pivotNode->right)) +
                            1;
        newParrent->height = _max(_getHeight(newParrent->left),
                                  _getHeight(newParrent->right)) +
                             1;

        return newParrent;
    }

    AVLNode *_leftRotate(AVLNode *pivotNode)
    {
        AVLNode *newParrent = pivotNode->right;
        pivotNode->right = newParrent->left;
        newParrent->left = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left),
                                 _getHeight(pivotNode->right)) +
                            1;
        newParrent->height = _max(_getHeight(newParrent->left),
                                  _getHeight(newParrent->right)) +
                             1;

        return newParrent;
    }

    AVLNode *_leftCaseRotate(AVLNode *node)
    {
        return _rightRotate(node);
    }

    AVLNode *_rightCaseRotate(AVLNode *node)
    {
        return _leftRotate(node);
    }

    AVLNode *_leftRightCaseRotate(AVLNode *node)
    {
        node->left = _leftRotate(node->left);
        return _rightRotate(node);
    }

    AVLNode *_rightLeftCaseRotate(AVLNode *node)
    {
        node->right = _rightRotate(node->right);
        return _leftRotate(node);
    }

    int _getBalanceFactor(AVLNode *node)
    {
        if (node == NULL)
            return 0;
        return _getHeight(node->left) - _getHeight(node->right);
    }

    AVLNode *_insert_AVL(AVLNode *node, int value)
    {

        if (node == NULL)
            return _avl_createNode(value);
        if (value < node->data)
            node->left = _insert_AVL(node->left, value);
        else if (value > node->data)
            node->right = _insert_AVL(node->right, value);

        node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right));

        int balanceFactor = _getBalanceFactor(node);

        if (balanceFactor > 1 && value < node->left->data)
            return _leftCaseRotate(node);
        if (balanceFactor > 1 && value > node->left->data)
            return _leftRightCaseRotate(node);
        if (balanceFactor < -1 && value > node->right->data)
            return _rightCaseRotate(node);
        if (balanceFactor < -1 && value < node->right->data)
            return _rightLeftCaseRotate(node);

        return node;
    }

    AVLNode *_findMinNode(AVLNode *node)
    {
        AVLNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        return currNode;
    }

    AVLNode *_remove_AVL(AVLNode *node, int value)
    {
        if (node == NULL)
            return node;
        if (value > node->data)
            node->right = _remove_AVL(node->right, value);
        else if (value < node->data)
            node->left = _remove_AVL(node->left, value);
        else
        {
            AVLNode *temp;
            if ((node->left == NULL) || (node->right == NULL))
            {
                temp = NULL;
                if (node->left == NULL)
                    temp = node->right;
                else if (node->right == NULL)
                    temp = node->left;

                if (temp == NULL)
                {
                    temp = node;
                    node = NULL;
                }
                else
                    *node = *temp;

                free(temp);
            }
            else
            {
                temp = _findMinNode(node->right);
                node->data = temp->data;
                node->right = _remove_AVL(node->right, temp->data);
            }
        }

        if (node == NULL)
            return node;

        node->height = _max(_getHeight(node->left), _getHeight(node->right)) + 1;

        int balanceFactor = _getBalanceFactor(node);

        if (balanceFactor > 1 && _getBalanceFactor(node->left) >= 0)
            return _leftCaseRotate(node);

        if (balanceFactor > 1 && _getBalanceFactor(node->left) < 0)
            return _leftRightCaseRotate(node);

        if (balanceFactor < -1 && _getBalanceFactor(node->right) <= 0)
            return _rightCaseRotate(node);

        if (balanceFactor < -1 && _getBalanceFactor(node->right) > 0)
            return _rightLeftCaseRotate(node);

        return node;
    }

    void _inorderRight(AVLNode *node, int it)
    {
        if (columnValues[it] == 0)
        {
            columnValues[it] += node->data;
        }
        it++;

        if (node->left != NULL)
        {
            _inorderLeft(node, it);
        }
        else
        {
            _inorderRight(node->right, it);
        }
    }

    void _inorderLeft(AVLNode *node, int it)
    {
        if (columnValues[it] == 0)
        {
            columnValues[it] += node->data;
        }
        it--;

        if (node->right != NULL)
        {
            _inorderRight(node, it);
        }
        else
        {
            _inorderRight(node->right, it);
        }
    }

    void _inorder(AVLNode *node)
    {
        int it = 0;
        if (node)
        {   
            _inorderLeft(node, it);
            // cout << node->data;
            
            _inorderRight(node, it);
        }
    }

    void checkChild(AVLNode *node) 
    {
        AVLNode *rightpointer = node;
        AVLNode *leftpointer = node;
        // AVLNode *leftmostptr;
        if (leftpointer->left != NULL)
        {
            column++;
            checkChild(leftpointer->left);
        }
        else
        {
            return;
        }

        if (node->right != NULL)
        {
            column++;
            checkChild(rightpointer->right);
        }
        else
        {
            return;
        }

        leftmostptr = leftpointer;
        // int columnValues[column];
    
        // cout << leftmostptr->data;
        // cout << leftmostptr->right->data;
    }

public:

    void treeChecking()
    {
        if (_root->left != NULL && _root->right != NULL)
        {
            checkChild(_root);
        }
    }

    void init()
    {
        _root = NULL;
        _size = 0U;
    }

    bool isEmpty()
    {
        return _root == NULL;
    }

    bool find(int value)
    {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL)
            return false;

        if (temp->data == value)
            return true;
        else
            return false;
    }

    void insert(int value)
    {
        if (!find(value))
        {
            _root = _insert_AVL(_root, value);
            _size++;
        }
    }

    void remove(int value)
    {
        if (find(value))
        {
            _root = _remove_AVL(_root, value);
            _size--;
        }
    }

    void inorder()
    {
        this->_inorder(_root);
    }

    void leftInorder()
    {
        this->_inorder(leftmostptr);
    }
};

int main() {
    int a = sizeof(columnValues) / sizeof(columnValues[0]);

    AVL tree;
    tree.init();

    int p;
    int key;
    cin >> p;

    for (int i = 0; i < p; i++)
    {
        string command;
        int dat = 0;
        cin >> command;
        if (command == "insert")
        {
            cin >> dat;
            tree.insert(dat);
        }
        else
        {
            tree.treeChecking();
        }
    }

    // cin >> key;
    tree.leftInorder();
    cout << column;

    for (int i = 0; i < a; i++)
    {
        if (columnValues[i] == NULL || columnValues[i] == 0)
        {
            break;
        }
        else
        {
            cout << columnValues[i];
        }
    }
    return 0;
}