#include <string>
#include <vector>
#include <algorithm>
#include "SuffixArray.h"
using namespace std;

/**
 * Implement suffix_array() correctly
 */
vector<unsigned int> suffix_array(const string & s) {
    vector<std::pair<string, unsigned int>> suffixArr;
    for (unsigned int i = 0; i < s.length(); i++) suffixArr.push_back(std::make_pair(s.substr(i, s.length() - i), i));
    sort(suffixArr.begin(), suffixArr.end());
    vector<unsigned int> res;
    for (auto p : suffixArr) res.push_back(p.second);
    return res;
}
