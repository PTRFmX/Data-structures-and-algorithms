/**
 * Leetcode 10: Regular Expression Matching
 * Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
*/

#include <stdio.h>
#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * Correct but TLE solution 
 */
bool regexMatchTLE(string s, string p) {
    unsigned int s_len = s.length();
    unsigned int p_len = p.length();
    if (!p_len) return !s_len;
    bool first_match = s_len && (p[0] == s[0] || p[0] == '.');
    // If we discover a '*' then do repeat match
    if (p_len >= 2 && p[1] == '*') {
        // This variable stores the value if we repeat the character 0 time (skip the *)
        bool skip_kleene_star = regexMatchTLE(s, p.substr(2));
        // This variable stores the value if we repeat the character 1 time
        bool repeat_one_time = first_match && regexMatchTLE(s.substr(1), p);
        return skip_kleene_star || repeat_one_time;
    }
    // If not, then we just move to the next char
    return first_match && regexMatchTLE(s.substr(1), p.substr(1));
}

/**
 * Accepted solution (TLE solution with memo)
*/
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};
typedef unordered_map<pair<unsigned int, unsigned int>, bool, hash_pair> rg_map;
bool regexMatchDp(unsigned int i, unsigned int j, rg_map* map, string s, string p) {
    rg_map::const_iterator itr = map->find(make_pair(i, j));
    if (itr != map->end()) return itr->second;
    if (j == p.length()) return i == s.length();
    bool first_match = s.length() && (p[0] == s[0] || p[0] == '.');
    bool ans;
    if (j <= p.length() - 2 && p[j + 1] == '*') {
        ans = regexMatchDp(i, j + 2, map, s, p) || first_match && regexMatchDp(i + 1, j, map, s, p);
    }
    else {
        ans = first_match && regexMatchDp(i + 1, j + 1, map, s, p);
    }
    map->insert({make_pair(i, j), ans});
    return ans;
}
bool regexMatch(string s, string p) {
    rg_map map;
    return regexMatchDp(0, 0, &map, s, p);
}


int main(int argc, char** argv) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s, p;
        cin >> s >> p;
        cout << regexMatch(s, p) << endl;
    }
}