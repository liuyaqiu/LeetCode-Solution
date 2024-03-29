#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Peeking Iterator
 *
 * Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() operation -- it essentially peek() at the element that will be returned by the next call to next().
 *
 * Here is an example. Assume that the iterator is initialized to the beginning of the list: [1, 2, 3].
 *
 * Call next() gets you 1, the first element in the list.
 *
 * Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.
 *
 * You call next() the final time and it returns 3, the last element. Calling hasNext() after that should return false.
 *
 * Hint:
 *
 * Think of "looking ahead". You want to cache the next element.
 * Is one variable sufficient? Why or why not?
 * Test your design with call order of peek() before next() vs next() before peek().
 * For a clean implementation, check out Google's guava library source code.
 *
 *
 */

class Iterator {
    struct Data;
    Data* data;

public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();

    int next();
    bool hasNext() const;
};

class PeekingIterator: public Iterator {
    bool hasPeeked;
    int peekedElement;

public:
    PeekingIterator(const vector<int>& nums): Iterator(nums) {
        hasPeeked = false;
        peekedElement = 0;
    }

    int peek() {
        if(!hasPeeked) {
            peekedElement = Iterator::next();
            hasPeeked = true;
        }
        return peekedElement;
    }

    int next() {
        if(!hasPeeked) {
            return Iterator::next();
        }
        int result = peekedElement;
        hasPeeked = false;
        peekedElement = 0;
        return result;
    }

    bool hasNext() const {
        return hasPeeked || Iterator::hasNext();
    }
};

