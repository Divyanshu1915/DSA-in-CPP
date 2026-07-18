#include <iostream>
using namespace std;

struct TreeNode {
    char data;
    TreeNode *left;
    TreeNode *right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(TreeNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

TreeNode* createNode(char data) {
    TreeNode* node = new TreeNode;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

TreeNode* rightRotate(TreeNode* y) {
    cout << "Rotate right on node " << y->data << endl;

    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

TreeNode* leftRotate(TreeNode* x) {
    cout << "Rotate left on node " << x->data << endl;

    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

int getBalance(TreeNode* node) {
    if (node == NULL)
        return 0;

    return getHeight(node->left) - getHeight(node->right);
}

TreeNode* insert(TreeNode* root, char data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrderTraversal(TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = NULL;

    char letters[] = {'C', 'B', 'E', 'A', 'D', 'H', 'G', 'F'};
    int n = sizeof(letters) / sizeof(letters[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, letters[i]);
    }

    cout << "Inorder Traversal: ";
    inOrderTraversal(root);

    return 0;
}