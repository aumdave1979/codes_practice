#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
class BST
{
    Node *root;
    Node *insert(Node *node, int val)
    {
        if (node == nullptr)
        {
            return new Node(val);
        }
        if (node->data > val)
        {
            node->left = insert(node->left, val);
        }
        else if (node->data < val)
        {
            node->right = insert(node->right, val);
        }
        return node;
    }
    void inorder(Node *node)
    {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST()
    {
        root = nullptr;
    }
    void insertNode(int val)
    {
        root = insert(root, val);
    }
    void display()
    {
        inorder(root);
    }
};
int main()
{
    BST bst;
    bst.insertNode(61);
    bst.display();
    bst.insertNode(6);
    bst.display();
    bst.insertNode(161);
    bst.display();
    bst.insertNode(101);
    bst.display();
    bst.insertNode(11);
    bst.display();
    return 0;
}