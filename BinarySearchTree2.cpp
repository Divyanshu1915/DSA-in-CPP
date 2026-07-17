#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int value) {
    Node* newNode = new Node(value);

    if (root == NULL)
        return newNode;

    Node* current = root;

    while (true) {
        if (value < current->data) {
            if (current->left == NULL) {
                current->left = newNode;
                break;
            }
            current = current->left;
        }
        else if (value > current->data) {
            if (current->right == NULL) {
                current->right = newNode;
                break;
            }
            current = current->right;
        }
        else {
            // Duplicate value
            delete newNode;
            break;
        }
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(13);

    root->left = new Node(7);
    root->right = new Node(15);

    root->left->left = new Node(3);
    root->left->right = new Node(8);

    root->right->left = new Node(14);
    root->right->right = new Node(19);

    root->right->right->left = new Node(18);

    // Insert a new node
    root = insert(root, 10);

    cout << "Inorder Traversal: ";
    inorder(root);

    return 0;
}