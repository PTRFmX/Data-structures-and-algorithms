#include "BloomFilter.h"
#include "HashFunctions.h"
#include <iostream>
/**
 * Implement insert() correctly
 */
void BloomFilter::insert(const string & s) {
    for (unsigned int i = 0; i < K; ++i) bits[hash_functions[i](s) % M] = true;
}

/**
 * Implement find() correctly
 */
bool BloomFilter::find(const string & s) {
    for (unsigned int i = 0; i < K; ++i)
        if (!bits[hash_functions[i](s) % M]) return false;
    return true;
}
