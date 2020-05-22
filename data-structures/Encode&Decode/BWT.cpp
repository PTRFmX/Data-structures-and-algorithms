#include <string>
#include <vector>
#include <algorithm>
#include "BWT.h"
using namespace std;

/**
 * Implement bwt() correctly
 */
string bwt(const string & str) {
    vector<string> bwu;
    string s = str;
    for (unsigned int i = 0; i < s.length(); i++) {
        s.insert(0, s.substr(s.length() - 1, 1));
        s.pop_back();
        bwu.push_back(s);
    }
    sort(bwu.begin(), bwu.end());
    string res;
    for (string s : bwu) res.push_back(s.at(s.length() - 1));
    return res;
}
