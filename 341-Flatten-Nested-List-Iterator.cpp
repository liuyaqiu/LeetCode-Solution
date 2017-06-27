#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
 * Flatten Nested List Iterator
 *
 * Given a nested list of integers, implement an iterator to flatten it.
 *
 * Each element is either an integer, or a list -- whose elements may also be integers or other lists.
 *
 * Example 1:
 * Given the list [[1,1],2,[1,1]],
 *
 * By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
 *
 * Example 2:
 * Given the list [1,[4,[6]]],
 *
 * By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].
 *
 *
 */

class NestedInteger {
public:
    bool isInteger() const;

    int getInteger() const;

    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    stack<NestedInteger> stk;
    void insert(NestedInteger cur) {
        if(cur.isInteger())
            stk.push(cur);
        else {
            vector<NestedInteger> list = cur.getList();
            for(auto iter = list.rbegin(); iter != list.rend(); iter++)
                insert(*iter);
        }
    }

public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        for(auto iter = nestedList.rbegin(); iter != nestedList.rend(); iter++) {
            insert(*iter);
        }
    }

    int next() {
        if(stk.empty())
            return -1;
        else
            return stk.top().getInteger();
    }

    bool hasNext() {
        return !stk.empty();
    }
};

