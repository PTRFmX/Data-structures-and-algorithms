/**
 * Leetcode 651: The 4-keys keyboard problem
 * Imagine you have a special keyboard with the following keys:
 * Key 1: (A): Print one 'A' on screen.
 * Key 2: (Ctrl-A): Select the whole screen.
 * Key 3: (Ctrl-C): Copy selection to buffer.
 * Key 4: (Ctrl-V): Print buffer on screen appending it after what has already been printed.
 * Now, you can only press the keyboard for N times (with the above four keys), find out the maximum numbers of 'A' you can print on screen.
*/

#include <stdio.h>
#include <iostream>

using namespace std;

/**
 * This solution observes the fact that there are only two ways to produce the max amount of 'A's
 * 1. A, A, A, A, ..., A (All 'A's)
 * 2. A, A, ..., C-A, C-C, C-V, ..., C-A, C-C, C-V ('A's followed by 'C-A, C-C, C-V's )
*/
int solve(int N) {
    // Initialize the num_a array, where num_a[i] = the max amount of 'A's possible after i operations
    int num_a[N + 1];
    for (int i = 0; i < N + 1; i++) num_a[i] = 0;
    // Construct the num_a array
    for (int i = 1; i < N + 1; i++) {
        // If press A
        num_a[i] = num_a[i - 1] + 1;
        // If not press A
        for (int j = 2; j < i; j++) {
            num_a[i] = max(num_a[i], num_a[j - 2] * (i - j + 1));
        }
    }
    return num_a[N];
}

int main(int argc, char** argv) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        cout << solve(m) << endl;
    }
}