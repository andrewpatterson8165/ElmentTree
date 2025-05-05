#include <iostream>
#include <string>

struct Node {
    std::string data;
    Node* left;
    Node* right;
    Node(std::string val) : data(val), left(nullptr), right(nullptr) {}
};

bool search(Node* root, const std::string& target) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == target) {
        return true;
    }
    if (target < root->data) {
        return search(root->left, target);
    } else {
        return search(root->right, target);
    }
}

int main() {
    Node* root = new Node("apple");
    root->left = new Node("banana");
    root->right = new Node("cherry");
    root->left->left = new Node("grape");

    std::cout << "Search for 'banana': " << search(root, "banana") << std::endl;
    std::cout << "Search for 'orange': " << search(root, "orange") << std::endl;

    return 0;
}
