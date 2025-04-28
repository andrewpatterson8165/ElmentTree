#include "Element.h"




#include "Element.h"


Element::Element(string name,
                 unsigned short id,
                 Element* parent)
{
        _name = name;
        _id = id;
        _parent = parent;
        _hasChildren = false;
        _childCount = 0;
        _next = nullptr;
        _previous = nullptr;
        _childHead = nullptr;
}

Element::~Element()
{
    
}

Element::Element(const Element& other)
{
   
    _name = other._name;
    _id = other._id;
    _parent = other._parent;
    _hasChildren = other._hasChildren;
    _parent = other._parent;
    _next = other._next;
    _childHead = other._childHead;
    _previous = other._previous;
   
}


#include <iostream>

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the binary tree
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function for inorder traversal (Left, Root, Right)
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Function for preorder traversal (Root, Left, Right)
void preorderTraversal(Node* root) {
    if (root != nullptr) {
        std::cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function for postorder traversal (Left, Right, Root)
void postorderTraversal(Node* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        std::cout << root->data << " ";
    }
}

// Function to free the memory allocated for the tree
void freeTree(Node* root) {
    if (root != nullptr) {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

int main() {
    Node* root = nullptr;

    // Inserting nodes
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    std::cout << "Inorder traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Preorder traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "Postorder traversal: ";
    postorderTraversal(root);
    std::cout << std::endl;

    // Free allocated memory
    freeTree(root);

    return 0;
}
