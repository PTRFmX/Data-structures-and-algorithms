/**
 * Leetcode 877: The stone-game problem
 * Alex and Lee play a game with piles of stones.
 * There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]
 * The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.
 * Alex and Lee take turns, with Alex starting first.
 * Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.
 * This continues until there are no more piles left, at which point the person with the most stones wins.
 * Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.
*/

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

// By mathematical induction, we can confirm that the first stone-taker will always win the game
bool solve_1(vector<int>& piles) {
    return true;
}

// Solution using DP
typedef pair<int, int> s_pair;
bool solve_2(vector<int>& piles) {
    int len = piles.size();
    /** 
    * Initialize the dp array all_pairs
    * all_pairs[i][j].first is the largest score that the first stone-taker gets between piles i and j 
    * all_pairs[i][j].second is the largest score that the second stone-taker gets between piles i and j 
    */
    s_pair all_pairs[len][len];
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) all_pairs[i][j] = make_pair(0, 0);
        // If there's only one pile, then the first one takes it
        all_pairs[i][i] = make_pair(piles[i], 0);
    }

    // Loop through the dp array
    for (int i = 1; i < len; i++) {
        for (int j = 0; j < len - i; j++) {
            int m = j; // start index
            int n = j + i; // end index
            // If to choose left, total = left pile score + next round score from piles (m + 1, n)
            int left = piles[m] + all_pairs[m + 1][n].second;
            // If to choose right, total = right pile score + next round score from piles (m, n - 1)
            int right = piles[n] + all_pairs[m][n - 1].second;
            /**
             * Calculate the current score
             * If the left side is greater then choose left and the other guy choose first for the next round 
             * If the right side is greater then choose right and ...
            */
            all_pairs[m][n] = left > right ? make_pair(left, all_pairs[m + 1][n].first) : make_pair(right, all_pairs[m][n - 1].first);
        }
    }

    return all_pairs[0][len - 1].first > all_pairs[0][len - 1].second;
}

int main(int argc, char** argv) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int size;
        cin >> size;
        vector<int> all_piles;
        for (int j = 0; j < size; ++j) {
            int tmp;
            cin >> tmp;
            all_piles.push_back(tmp);
        }
        cout << solve_1(all_piles) << endl;
        cout << solve_2(all_piles) << endl;
    }
}
