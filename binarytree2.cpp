#include <iostream>
using namespace std;

// Node class
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Preorder Traversal (Root -> Left -> Right)
void preorder(TreeNode* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder Traversal (Left -> Root -> Right)
void inorder(TreeNode* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Postorder Traversal (Left -> Right -> Root)
void postorder(TreeNode* root) {
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    // Create nodes
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Preorder Traversal: ";
    preorder(root);

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    // Free memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}