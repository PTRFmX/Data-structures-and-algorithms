#include "Set.h"
#include <algorithm>
/**
 * Implement the ArrayListSet methods correctly
 */
unsigned int ArrayListSet::size() {
    return arr.size();
}

void ArrayListSet::insert(string s) {
    if (find(s)) return;
    arr.push_back(s);
}

void ArrayListSet::remove(const string & s) {
    for (std::vector<string>::iterator itr = arr.begin(); itr != arr.end(); itr++) {
        if (*itr == s) {
            arr.erase(itr);
            return;
        }
    }
}

bool ArrayListSet::find(const string & s) {
    return std::find(arr.begin(), arr.end(), s) != arr.end();
}
