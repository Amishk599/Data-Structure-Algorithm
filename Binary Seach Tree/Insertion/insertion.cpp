#include <bits/stdc++.h>
using namespace std;

//structre of BST node
struct node
{
    int data;
    struct node *left, *right;
};

//new node creation
node *getNewNode(int data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

//function to insert new node in the BST
node *insert(node *root, int data)
{
    if (root == NULL)
        root = getNewNode(data);

    else if (data <= root->data)
        root->left = insert(root->left, data);

    else
        root->right = insert(root->right, data);

    return root;
}

//priting the BST in inorder
void Inorder(node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

int main()
{
    node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
    Inorder(root);
    return 0;
}
