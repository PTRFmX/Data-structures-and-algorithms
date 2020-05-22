#include "Set.h"

/**
 * Implement the RedBlackTreeSet methods correctly
 */
unsigned int RedBlackTreeSet::size() {
    return rbt.size();
}

void RedBlackTreeSet::insert(string s) {
    if (find(s)) return;
    rbt.insert(s);
}

void RedBlackTreeSet::remove(const string & s) {
    for (std::set<string>::iterator itr = rbt.begin(); itr != rbt.end(); ++itr) {
        if (*itr == s) {
            rbt.erase(itr);
            return;
        }
    }
}

bool RedBlackTreeSet::find(const string & s) {
    return rbt.find(s) != rbt.end();
}
