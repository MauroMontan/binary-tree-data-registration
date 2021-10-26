#ifndef BINARYTREE_H
#define BINARYTREE_H


class binaryTree
{
  public:
    int data;

    binaryTree *left,*right;
    binaryTree(int data);
    binaryTree *insert(binaryTree *root,int data)
    {
      if (root==nullptr)
      {
        root = new binaryTree(data);
        return root;
      }
      if (data<= root->data)
      {
        root->left=insert(root->left,data);
      }
      else {
      root->right = insert(root->right,data);
      }
      return root;
    }

    void insert(int data);
    void traverse();
    bool search(binaryTree *root,int id);
};




#endif // BINARYTREE_H
