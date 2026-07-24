#include <iostream>
using namespace std;

class TreeNode {
public:
    char data;
    TreeNode* left;
    TreeNode* right;

    // Constructor
    TreeNode(char value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Postorder Traversal (Left -> Right -> Root)
void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << ", ";
}

int main() {
    // Create nodes
    TreeNode* root = new TreeNode('R');
    TreeNode* nodeA = new TreeNode('A');
    TreeNode* nodeB = new TreeNode('B');
    TreeNode* nodeC = new TreeNode('C');
    TreeNode* nodeD = new TreeNode('D');
    TreeNode* nodeE = new TreeNode('E');
    TreeNode* nodeF = new TreeNode('F');
    TreeNode* nodeG = new TreeNode('G');

    // Build the tree
    root->left = nodeA;
    root->right = nodeB;

    nodeA->left = nodeC;
    nodeA->right = nodeD;

    nodeB->left = nodeE;
    nodeB->right = nodeF;

    nodeF->left = nodeG;

    // Postorder Traversal
    cout << "Postorder Traversal: ";
    postOrderTraversal(root);

    // Free memory
    delete nodeG;
    delete nodeF;
    delete nodeE;
    delete nodeB;
    delete nodeC;
    delete nodeD;
    delete nodeA;
    delete root;

    return 0;
}