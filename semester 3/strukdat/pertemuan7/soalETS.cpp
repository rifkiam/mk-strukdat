#include <iostream>
using namespace std;

// node
struct Node{
  string label;
  Node *left, *right, *parent;
};

// variabel pointer global
Node *root, *newNode;

// create New Tree
void createNewTree( string label )
{

  if( root != NULL )
    cout << "\nTree sudah dibuat" << endl;
  else{
    root = new Node();
    root->label = label;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
    cout << "\nNode " << label << " berhasil dibuat menjadi root." << endl;
  }

}

// insert Left
Node *insertLeft( string label, Node *node )
{
  if( root == NULL ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    return NULL;
  }else{
    // cek apakah anak kiri ada atau tidak
    if( node->left != NULL ){
      // kalau ada
      cout << "\nNode "<< node->label << " sudah ada anak kiri!!" << endl;
      return NULL;
    }else{
      // kalau tidak ada
      newNode = new Node();
      newNode->label = label;
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->parent = node;
      node->left = newNode;
      cout << "\nNode " << label << " berhasil ditambahkan ke anak kiri " << newNode->parent->label << endl;
      return newNode;
    }

  }
}

// insert right
Node *insertRight( string label, Node *node )
{
  if( root == NULL ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    return NULL;
  }else{
    // cek apakah anak kiri ada atau tidak
    if( node->right != NULL ){
      // kalau ada
      cout << "\nNode " << node->label << " sudah ada anak kanan!!" << endl;
      return NULL;
    }else{
      // kalau tidak ada
      newNode = new Node();
      newNode->label = label;
      newNode->left = NULL;
      newNode->right = NULL;
      newNode->parent = node;
      node->right = newNode;
      cout << "\nNode " << label << " berhasil ditambahkan ke anak kanan " << newNode->parent->label << endl;
      return newNode;
    }

  }
}

// Empty
bool empty()
{
  if( root == NULL )
    return true;
  else
    return false;
}

// update
void update(string label, Node *node)
{
  if( !root ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  }else{
    if( !node )
      cout << "\nNode yang ingin diganti tidak ada!!" << endl;
    else{
      string temp = node->label;
      node->label = label;
      cout << "\nLabel node " << temp << " berhasil diubah menjadi " << label << endl;
    }
  }
}

// Tranversal
// preOrder
void preOrder( Node *node = root )
{

  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{

    if( node != NULL ){
      cout << node->label << ", ";
      preOrder(node->left);
      preOrder(node->right);
    }

  }

}

// inOrder
void inOrder( Node *node = root )
{

  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{

    if( node != NULL ){
      inOrder(node->left);
      cout << node->label << ", ";
      inOrder(node->right);
    }

  }

}

// postOrder
void postOrder( Node *node = root )
{

  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{

    if( node != NULL ){
      postOrder(node->left);
      postOrder(node->right);
      cout << node->label << ", ";
    }

  }

}

//Search and change
void searchAndChange(string value, Node *node = root)
{
  if( !root )
  {
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  }
  else
  {
    if( node != NULL )
    {
      if (node->label == value)
      {
        cout << "Found " << value << ", change value to: " << endl;
        cin >> node->label;
        cout << endl << value << " changed to " << node->label;
        return;
      }
      searchAndChange(value, node->left);
      searchAndChange(value, node->right);
    }
  }

}


// deleteTree
void deleteTree( Node *node )
{

  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{

    if( node != NULL ){
      if( node != root ){
        node->parent->left = NULL;
        node->parent->right = NULL;
      }
      deleteTree(node->left);
      deleteTree(node->right);
      
      if( node == root ){
        delete root;
        root = NULL;
      }else{
        delete node;
      }

    }

  }

}

// clear
void clear(){
  if( !root )
    cout << "\nBuat tree terlebih dahulu!!" << endl;
  else{
    deleteTree(root);
    cout << "\nTree berhasil dihapus."  << endl;
  }
}


// size
int size(Node *node = root){
  if( !root ){
    cout << "\nBuat tree terlebih dahulu!!" << endl;
    return 0;
  }else{

    if( !node ){
      return 0;
    }else{
      return 1 + size( node->left ) + size(node->right);
    }

  }
}

// height
int height( Node *node = root )
{
  if( !root ){
      cout << "\nBuat tree terlebih dahulu!!" << endl;
      return 0;
    }else{
      if( !node ){
        return 0;
      }else{
        int heightKiri = height( node->left );
        int heightKanan = height( node->right );

        if( heightKiri >= heightKanan ){
          return heightKiri + 1;
        }else{
          return heightKanan + 1;
        }

      }
    }
}

int main()
{

  /*

  Fungsi - fungsi yang digunakan:
  createNewTree();
  insertLeft();
  insertRight();
  searchAndChange(); //untuk setiap metode traversal (PreOrder, InOrder, dan PostOrder)
  preOrder();
  inOrder();
  postOrder();

  */

  createNewTree("Leluhur"); // Depth 0

  Node* Moyang1 = insertLeft("Saudara", root); // Depth 1
  Node* Moyang2 = insertRight("Lin", root);
  Node* Buyut1 = insertLeft("Sulkan", Moyang2); // Depth 2
  Node* Buyut2 = insertRight("Suti", Moyang2);
  Node* Nenek1 = insertLeft("Harimi", Buyut2); // Depth 3
  Node* Nenek2 = insertRight("Darwin", Buyut2);
  Node* Budhe = insertLeft("Alvia", Nenek1); // Depth 4
  Node* Ibu = insertRight("Nurul", Nenek1);
  Node* SepIbu1 = insertLeft("Yan", Nenek2);
  Node* SepIbu2 = insertRight("Sani", Nenek2);
  Node* Sepupu1 = insertLeft("Faris", Budhe); // Depth 5
  Node* Sepupu2 = insertRight("Nisa", Budhe);
  Node* Saudara1 = insertLeft("Nadiah", Ibu);
  Node* Saudara2 = insertRight("Sofi", Ibu);
  Node* Ponakan1 = insertLeft("Dina", Sepupu1);
  Node* Ponakan2 = insertRight("Doni", Sepupu1);

  searchAndChange("Sani");

  cout << "\nPreOrder :" << endl;
  preOrder(root);
  cout << "\n" << endl;

  searchAndChange("Sofi");

  cout << "\nInOrder :" << endl;
  inOrder(root);
  cout << "\n" << endl;

  searchAndChange("Darwin");

  cout << "\nPostOrder :" << endl;
  postOrder(root);
  cout << "\n" << endl;  

  inOrder(Budhe);

  cout << "Height: " << height() << endl;
  cout << "Depth: " << height() - 1;

  return 0;
}