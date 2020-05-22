#include "BST.h"
#include <vector>

/**
 * Implement the BST constructor
 */
BST::BST() {
    root = NULL;
    numElements = 0;
}

/**
 * Implement the BST destructor
 */
BST::~BST() {
    clear();
}

/**
 * Implement size() correctly
 */
unsigned int BST::size() const {
    return numElements;
}

/**
 * Helper method for the clear() method
 * Delete all nodes via post-order traversal
 */
void clearRecursive(BST::Node* node) {
    if (node == NULL) return;
    clearRecursive(node->leftChild);
    clearRecursive(node->rightChild);
    delete node;
}

/**
 * Implement clear() correctly without memory leaks
 */
void BST::clear() {
    clearRecursive(root);
    root = NULL;
    numElements = 0;
}

/**
 * Implement insert() correctly
 */
bool BST::insert(int element) {
    if (root == NULL) {
        root = new Node(element);
        numElements++;
        return true;
    }
    Node* currNode = root;
    while (currNode != NULL && currNode->data != element) {
        if (currNode->data < element) {
            if (currNode->rightChild == NULL) {
                // Perform insertion
                Node* newNode = new Node(element);
                currNode->rightChild = newNode;
                numElements++;
                return true;
            }
            currNode = currNode->rightChild;
        }
        else {
            if (currNode->leftChild == NULL) {
                // Perform insertion
                Node* newNode = new Node(element);
                currNode->leftChild = newNode;
                numElements++;
                return true;
            }
            currNode = currNode->leftChild;
        }
    }
    return false;
}

/**
 * Implement find() correctly
 */
bool BST::find(const int & query) const {
    Node* currNode = root;
    while (currNode != NULL && currNode->data != query) {
        if (currNode->data < query) {
            currNode = currNode->rightChild;
        }
        else {
            currNode = currNode->leftChild;
        }
    }
    if (currNode == NULL) return false;
    return true;
}

/**
 * Implement the getLeftMostNode() function correctly
 */
BST::Node* BST::getLeftMostNode() {
    Node* currNode = root;
    while (currNode->leftChild != NULL) currNode = currNode->leftChild;
    return currNode;
}

/**
 * Implement the BST::Node successor function correctly
 */
BST::Node* BST::Node::successor() {
    if (rightChild != NULL) return rightChild;
    Node* currNode = this;
    while (currNode->parent != NULL && currNode->parent->leftChild != currNode) {
        currNode = currNode->parent;
    }
    return currNode->parent;
}
