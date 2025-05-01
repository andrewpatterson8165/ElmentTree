#include <iostream>

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T data) : data(data), left(nullptr), right(nullptr) {}
    ~TreeNode() {
        delete left;
        delete right;
    }
};

template <typename T>
class BinaryTree {
public:
    TreeNode<T>* root;

    BinaryTree() : root(nullptr) {}
    ~BinaryTree() {
        delete root;
    }

    void insert(T data) {
        root = insertRecursive(root, data);
    }

    TreeNode<T>* search(T data) {
        return searchRecursive(root, data);
    }

    void printInOrder() {
        printInOrderRecursive(root);
        std::cout << std::endl;
    }

private:
    TreeNode<T>* insertRecursive(TreeNode<T>* node, T data) {
        if (node == nullptr) {
            return new TreeNode<T>(data);
        }

        if (data < node->data) {
            node->left = insertRecursive(node->left, data);
        } else {
            node->right = insertRecursive(node->right, data);
        }
        return node;
    }

    TreeNode<T>* searchRecursive(TreeNode<T>* node, T data) {
        if (node == nullptr || node->data == data) {
            return node;
        }

        if (data < node->data) {
            return searchRecursive(node->left, data);
        } else {
            return searchRecursive(node->right, data);
        }
    }
    
    void printInOrderRecursive(TreeNode<T>* node) {
        if (node != nullptr) {
            printInOrderRecursive(node->left);
            std::cout << node->data << " ";
            printInOrderRecursive(node->right);
        }
    }
};

int main() {
    BinaryTree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Inorder traversal: ";
    tree.printInOrder();

    TreeNode<int>* node = tree.search(40);
    if (node != nullptr) {
        std::cout << "Found node: " << node->data << std::endl;
    } else {
        std::cout << "Node not found" << std::endl;
    }

    return 0;
}
