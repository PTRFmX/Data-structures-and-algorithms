#include "Set.h"
#include <algorithm>
/**
 * Implement the LinkedListSet methods correctly
 */
unsigned int LinkedListSet::size() {
    return linked.size();
}

void LinkedListSet::insert(string s) {
    if (find(s)) return;
    linked.insert(linked.end(), s);
}

void LinkedListSet::remove(const string & s) {
    linked.remove(s);
}

bool LinkedListSet::find(const string & s) {
    return std::find(linked.begin(), linked.end(), s) != linked.end();
}
