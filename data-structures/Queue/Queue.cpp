#include "Queue.h"

/**
 * Implement Queue constructor
 */
Queue::Queue() {
    head = tail = NULL;
    numElements = 0;
}

/**
 * Implement the Queue destructor
 */
Queue::~Queue() {
    clear();
}

/**
 * Implement size() correctly
 */
unsigned int Queue::size() {
    return numElements;
}

/**
 * Implement clear() correctly without memory leaks
 */
void Queue::clear() {
    // Keep popping elements until empty
    while(size()) {
        pop();
    }
}

/**
 * Implement push() correctly
 */
void Queue::push(string s) {

    /* Create new node */
    Node* n = new Node(s);

    /* Insert to the queue */
    if (tail == NULL) {
        head = tail = n;
    }
    else {
        tail->next = n;
        tail = n;
    }

    /* Self-increment size */
    numElements++;
}

/**
 * Implement pop() correctly without memory leaks
 */
string Queue::pop() {

    /* Empty queue */
    if (head == NULL) return NULL;

    /* Pop from current queue */
    Node* tmp = head;
    string val = tmp->data;
    Node* next_node = tmp->next;

    /* Update head */
    head = next_node; 
    if (head == NULL) tail = NULL;

    /* Free node */
    delete tmp;

    /* Update size */
    numElements--;

    return val;
}
