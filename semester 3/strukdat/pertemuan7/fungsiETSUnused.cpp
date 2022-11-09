#include <iostream>
using namespace std;

struct Node{
  string label;
  Node *left, *right, *parent;
};

Node *root, *newNode;

// Identify
void identify( Node *node )
{
  if( !root )
  {
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  }

  else
  {
    if( !node )
    {
      cout << "\nNode yang ditunjuk tidak ada!!" << endl;
    }
    else
    {
      cout << "\nLabel Node : " << node->label << endl;
      cout << "Root Node : " << root->label << endl;
      
      if( !node->parent )
        cout << "Parent Node : (tidak punya orang tua)" << endl;
      else
        cout << "Parent Node : " << node->parent->label << endl;



      if( node->parent != NULL && node->parent->left != node && node->parent->right == node )

        cout << "Saudara : " << node->parent->left->label << endl;

      else if( node->parent != NULL && node->parent->right != node && 
      node->parent->left == node )

        cout << "Saudara : " << node->parent->right->label << endl;

      else

        cout << "Saudara : (tidak punya saudara)" << endl;




      if( !node->left )
        cout << "Anak Kiri Node : (tidak punya anak kiri)" << endl;
      else
        cout << "Anak Kiri Node : " << node->left->label << endl;

      if( !node->right )
        cout << "Anak Kanan Node : (tidak punya anak kanan)" << endl;
      else
        cout << "Anak Kanan Node : " << node->right->label << endl;



    }
    

  }
}

// retrieve
void retrieve( Node *node )
{
  if( !root ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  }else{
    if( !node )
      cout << "\nNode yang ditunjuk tidak ada!!" << endl;
    else{
      cout << "\nLabel node : " << node->label << endl;
    }
  }
}

// delete Sub
void deleteSub(Node *node){
  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{
    deleteTree(node->left);
    deleteTree(node->right);
    cout << "\nSubtree node " << node->label << " berhasil dihapus."  << endl;
  }
}

// characteristic
void charateristic()
{
  cout << "\nSize Tree : " << size() << endl;
  cout << "Height Tree : " << height() << endl;
  cout << "Average Node of Tree : " << size() / height() << endl;
}