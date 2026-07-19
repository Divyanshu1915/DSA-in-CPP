#include <iostream>
using namespace std;

class TreeNode {
public:
    char data;
    TreeNode *left, *right;
    int height;

    TreeNode(char value) {
        data = value;
        left = right = NULL;
        height = 1;
    }
};

// Get Height
int getHeight(TreeNode *node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Maximum of two numbers
int maxValue(int a, int b) {
    return (a > b) ? a : b;
}

// Get Balance Factor
int getBalance(TreeNode *node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Right Rotation
TreeNode* rightRotate(TreeNode *y) {
    TreeNode *x = y->left;
    TreeNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + maxValue(getHeight(y->left), getHeight(y->right));
    x->height = 1 + maxValue(getHeight(x->left), getHeight(x->right));

    return x;
}

// Left Rotation
TreeNode* leftRotate(TreeNode *x) {
    TreeNode *y = x->right;
    TreeNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + maxValue(getHeight(x->left), getHeight(x->right));
    y->height = 1 + maxValue(getHeight(y->left), getHeight(y->right));

    return y;
}

// Insert Node
TreeNode* insert(TreeNode *node, char data) {

    if (node == NULL)
        return new TreeNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + maxValue(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    // Left Right
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Right
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    // Right Left
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Inorder Traversal
void inOrderTraversal(TreeNode *node) {
    if (node == NULL)
        return;

    inOrderTraversal(node->left);
    cout << node->data << ", ";
    inOrderTraversal(node->right);
}

// Find Minimum Value Node
TreeNode* minValueNode(TreeNode *node) {
    TreeNode *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

// Delete Node
TreeNode* deleteNode(TreeNode *node, char data) {

    if (node == NULL)
        return node;

    if (data < node->data)
        node->left = deleteNode(node->left, data);

    else if (data > node->data)
        node->right = deleteNode(node->right, data);

    else {

        // One child or no child
        if (node->left == NULL) {
            TreeNode *temp = node->right;
            delete node;
            return temp;
        }

        else if (node->right == NULL) {
            TreeNode *temp = node->left;
            delete node;
            return temp;
        }

        // Two children
        TreeNode *temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }

    if (node == NULL)
        return node;

    node->height = 1 + maxValue(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // Left Left
    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    // Left Right
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Right
    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    // Right Left
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Main Function
int main() {

    TreeNode *root = NULL;

    char letters[] = {'C', 'B', 'E', 'A', 'D', 'H', 'G', 'F'};

    for (char letter : letters)
        root = insert(root, letter);

    cout << "Inorder Traversal: ";
    inOrderTraversal(root);

    cout << "\n\nDeleting A\n";

    root = deleteNode(root, 'A');

    cout << "Inorder Traversal: ";
    inOrderTraversal(root);

    return 0;
}