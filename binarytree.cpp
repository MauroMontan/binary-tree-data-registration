#include "binarytree.h"

#include <iostream>
#include <fstream>

using namespace std;

binaryTree::binaryTree(int data)
{
  this->data = data;
  this->left = nullptr;
  this->right = nullptr;
}

void binaryTree::insert(int data)
{
  insert(this, data);
}

void binaryTree::traverse()
{
  ofstream Archivo;

  if (this->left != nullptr)
  {
    this->left->traverse();
  }

  Archivo.open("tree.txt", ios::in | ios::app);
  if (Archivo.is_open())
  {
    Archivo << this->data << " ";
    Archivo.close();
  }

  cout << this->data << " ";
  if (this->right != nullptr)
  {
    this->right->traverse();
  }
}

bool binaryTree::search(binaryTree *root, int id)
{
  if (root == nullptr)
  {
    return false;
  }
  else if (root->data == id)
  {
    return true;
  }
  else if (id < root->data)
  {
    return search(root->left, id);
  }
  else
  {
    return search(root->right, id);
  }
}
