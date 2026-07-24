#include <iostream>
using namespace std;

// Structure for a tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

// Function to create a new tree node
TreeNode* newTreeNode(int data) {
    TreeNode* node = new TreeNode;

    node->data = data;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}

// Function for Inorder Traversal
void inOrderTraversal(TreeNode* node) {
    if (node == nullptr)
        return;

    inOrderTraversal(node->left);
    cout << node->data << ", ";
    inOrderTraversal(node->right);
}

int main() {
    TreeNode* root = newTreeNode(13);

    root->left = newTreeNode(7);
    root->right = newTreeNode(15);

    root->left->left = newTreeNode(3);
    root->left->right = newTreeNode(8);

    root->right->left = newTreeNode(14);
    root->right->right = newTreeNode(19);

    root->right->right->left = newTreeNode(18);

    cout << "Inorder Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // Free allocated memory
    delete root->right->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}