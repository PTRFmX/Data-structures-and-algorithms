#include "Set.h"

/**
 * Implement the MultiwayTrieSet constructor
 */
MultiwayTrieSet::MultiwayTrieSet() {
    root = new Node();
    numElements = 0;
}

void clear(MultiwayTrieSet::Node* node) {
    // Base case
    if (node == NULL) return;
    // Delete children
    std::unordered_map<char, MultiwayTrieSet::Node*>::iterator it;
    for (it = node->children.begin(); it != node->children.end(); ++it) {
        clear((*it).second);
    }
    // Delete self
    delete node;
}

/**
 * Implement the MultiwayTrieSet destructor
 */
MultiwayTrieSet::~MultiwayTrieSet() {
    clear(root);
    numElements = 0;
}

/**
 * Implement the MultiwayTrieSet methods correctly
 */
unsigned int MultiwayTrieSet::size() {
    return numElements;
}

void MultiwayTrieSet::insert(string s) {
    Node* n = root;
    std::unordered_map<char, Node*>::iterator it;
    for (unsigned int i = 0; i < s.length(); i++) {
        if ((it = n->children.find(s[i])) == n->children.end()) {
            Node* new_node = new Node();
            if (i == s.length() - 1) new_node->isWord = true;
            n->children.insert(make_pair(s[i], new_node));
            n = new_node;
            continue;
        }
        n = (*it).second;
    }
    numElements++;
}

void MultiwayTrieSet::remove(const string & s) {
    Node* n = root;
    std::unordered_map<char, Node*>::iterator it;
    for (char c : s) {
        // If some char in the string is not contained in the trie, just return
        if ((it = n->children.find(c)) == n->children.end()) return;
        n = (*it).second;
    }
    // Change the last node of the string to a non-word node
    (*it).second->isWord = false;
    numElements--;
}

bool MultiwayTrieSet::find(const string & s) {
    Node* n = root;
    std::unordered_map<char, Node*>::iterator it;
    for (char c : s) {
        // If some char in the string is not contained in the trie
        if ((it = n->children.find(c)) == n->children.end()) return false;
        n = (*it).second;
    }
    // Determine if the last node of the string is a word-node
    return (*it).second->isWord;
}
