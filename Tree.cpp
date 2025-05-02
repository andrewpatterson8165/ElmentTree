#include <iostream>
#include <vector>

class Node {
public:
    int data;
    std::vector<Node*> children;

    Node(int data) : data(data) {}

    ~Node() {
        for (Node* child : children) {
            delete child;
        }
    }

    void addChild(Node* child) {
        children.push_back(child);
    }
};

class NTree {
public:
    Node* root;

    NTree(int rootData) {
        root = new Node(rootData);
    }

    ~NTree() {
        delete root;
    }

    // Example method to print the tree (pre-order traversal)
    void printTree(Node* node) {
        if (node == nullptr) return;
        std::cout << node->data << " ";
        for (Node* child : node->children) {
            printTree(child);
        }
    }
};

int main() {
    NTree tree(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    Node* node7 = new Node(7);

    tree.root->addChild(node2);
    tree.root->addChild(node3);
    node2->addChild(node4);
    node2->addChild(node5);
    node3->addChild(node6);
    node3->addChild(node7);

    std::cout << "Tree (Pre-order traversal): ";
    tree.printTree(tree.root);
    std::cout << std::endl;

    return 0;
}
