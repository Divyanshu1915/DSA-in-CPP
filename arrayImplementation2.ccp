#include <iostream>
using namespace std;

// Structure for a tree node
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
};

// Function to create a new node
TreeNode* createNewNode(char data) {
    TreeNode* newNode = new TreeNode;

    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

// Function for Postorder Traversal
void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << ", ";
}

int main() {
    TreeNode* root = createNewNode('R');
    TreeNode* nodeA = createNewNode('A');
    TreeNode* nodeB = createNewNode('B');
    TreeNode* nodeC = createNewNode('C');
    TreeNode* nodeD = createNewNode('D');
    TreeNode* nodeE = createNewNode('E');
    TreeNode* nodeF = createNewNode('F');
    TreeNode* nodeG = createNewNode('G');

    // Create the binary tree
    root->left = nodeA;
    root->right = nodeB;

    nodeA->left = nodeC;
    nodeA->right = nodeD;

    nodeB->left = nodeE;
    nodeB->right = nodeF;

    nodeF->left = nodeG;

    // Traverse the tree
    cout << "Postorder Traversal: ";
    postOrderTraversal(root);
    cout << endl;

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