#include "BinaryTree.h"

int getMaxDepth(BinaryTree::Node* node) {
    if (node == NULL) return 0;
    return max(getMaxDepth(node->leftChild), getMaxDepth(node->rightChild)) + 1; 
}

void getBalanceFactors(BinaryTree::Node* node, unordered_map<int,int>* map) {
    if (node == NULL || map->count(node->label)) return;
    map->insert({node->label, getMaxDepth(node->rightChild) - getMaxDepth(node->leftChild)});
    getBalanceFactors(node->rightChild, map);
    getBalanceFactors(node->leftChild, map);
}

/**
 * Implement balanceFactors() correctly
 */
unordered_map<int,int> BinaryTree::balanceFactors() {
    unordered_map<int,int>* map = new unordered_map<int,int>();
    getBalanceFactors(BinaryTree::root, map);
    return *map;
}