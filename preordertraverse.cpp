#include <iostream>
using namespace std;

class TreeNode {
public:
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* createNewNode(char data) {
    return new TreeNode(data);
}

void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
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

    // Connect the nodes
    root->left = nodeA;
    root->right = nodeB;

    nodeA->left = nodeC;
    nodeA->right = nodeD;

    nodeB->left = nodeE;
    nodeB->right = nodeF;

    nodeF->left = nodeG;

    // Preorder Traversal
    cout << "Preorder Traversal: ";
    preOrderTraversal(root);

    // Free allocated memory
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