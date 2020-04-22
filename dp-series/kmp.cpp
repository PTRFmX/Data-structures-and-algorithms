
/**
 * Leetcode Question No.28
 * Find the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

#include <stdio.h>
#include <iostream>
#include <string>

// The of all chars (Based on the ASCII table)
#define NUM_OF_CHARS 256 

using namespace std;

int kmp(string haystack, string needle) {

    // Edge cases
    if (!needle.length()) return 0;
    if (!haystack.length()) return -1;

    /**
     * Initialize DFA
     * len: the number of states that our DFA needs to have
     * NUM_OF_CHARS: the number of inputs / alphabets that each state receives
    */
    unsigned int len = needle.length();
    int dfa[len][NUM_OF_CHARS];
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < NUM_OF_CHARS; j++) dfa[i][j] = 0;
    }

    dfa[0][needle.at(0)] = 1; // Base case
    int shadow_state = 0; // The shadow state is the state that contains the same prefix with the current state 
    for (int i = 1; i < len; i++) {
        // Loop through the needle, map the current state to the next state
        for (int j = 0; j < NUM_OF_CHARS; j++) {
            dfa[i][j] = needle.at(i) == j ? i + 1 : dfa[shadow_state][j];
        }
        // Loop through the needle, update the shadow states
        shadow_state = dfa[shadow_state][needle.at(i)];
    }

    // Perform search action
    int h_len = haystack.length();
    int j = 0; 
    for (int i = 0; i < h_len; i++) {
        j = dfa[j][haystack.at(i)];
        if (j == len) return i - len + 1;
    }

    return -1;
}

int main(int argc, char** argv) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string hs, nd;
        cin >> hs >> nd;
        cout << kmp(hs, nd) << endl;
    }
}