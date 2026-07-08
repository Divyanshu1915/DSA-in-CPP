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

    // Test
    cout << "root->right->left->data: "
         << root->right->left->data << endl;

    // Free memory
    delete nodeG;
    delete nodeF;
    delete nodeE;
    delete nodeB;
    delete nodeD;
    delete nodeC;
    delete nodeA;
    delete root;

    return 0;
}