// This Binary Tree can be stored in an Array starting with the root node R on index 0. The rest of the tree can be built by taking a node stored on index i, and storing its left child node on index 2⋅i+1, and its right child node on index 2⋅i+2.

// Below is an Array implementation of the Binary Tree.
#include <iostream>
using namespace std;

const int ARRAY_SIZE = 15;

// Function declarations
char* get_data(char binaryTreeArray[], int index);
int left_child_index(int index);
int right_child_index(int index);

int main() {
    char binaryTreeArray[ARRAY_SIZE] = {
        'R', 'A', 'B', 'C', 'D', 'E', 'F',
        '\0', '\0', '\0', '\0', '\0', '\0', 'G', '\0'
    };

    int rightChild = right_child_index(0);
    int leftChildOfRightChild = left_child_index(rightChild);

    char* data = get_data(binaryTreeArray, leftChildOfRightChild);

    if (data != nullptr && *data != '\0') {
        cout << "root.right.left.data: " << *data << endl;
    } else {
        cout << "No data found." << endl;
    }

    return 0;
}

// Returns the address of the data at the given index
char* get_data(char binaryTreeArray[], int index) {
    if (index >= 0 && index < ARRAY_SIZE) {
        return &binaryTreeArray[index];
    }
    return nullptr;
}

// Returns the index of the left child
int left_child_index(int index) {
    return 2 * index + 1;
}

// Returns the index of the right child
int right_child_index(int index) {
    return 2 * index + 2;
}