#include <iostream>
using namespace std;

struct BSTNode {
    BSTNode *left, *right;
    string nama;
};

struct BSTNode_multiple {
    BSTNode_multiple *next, **child;
    string nama;
};