#include <limits>
#include "CountMinSketch.h"
#include "HashFunctions.h"

/**
 * Implement increment() correctly
 */
void CountMinSketch::increment(const string & s) {
    for (unsigned int i = 0; i < K; ++i) count[i][hash_functions[i](s) % M] += 1;
}

/**
 * Implement find() correctly
 */
unsigned int CountMinSketch::find(const string & s) {
    unsigned int res = INT32_MAX;
    for (unsigned int i = 0; i < K; ++i) {
        unsigned int currVal = count[i][hash_functions[i](s) % M];
        if (currVal < res) res = currVal;
    }
    return res;
}