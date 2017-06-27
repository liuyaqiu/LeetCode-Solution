#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
 * Verify Preorder Serialization of a Binary Tree
 *
 * One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.
 *
 *          _9_
 *         /   \
 *        3     2
 *       / \   / \
 *      4   1  #  6
 *     / \ / \   / \
       # # # #   # #
 * For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
 *
 * Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.
 *
 * Each comma separated value in the string must be either an integer or a character '#' representing null pointer.
 * You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".
 *
 * Example 1:
 * "9,3,4,#,#,1,#,#,2,#,6,#,#"
 * Return true
 *
 * Example 2:
 * "1,#"
 * Return false
 *
 * Example 3:
 * "9,#,#,1"
 * Return false
 *
 *
 */

bool isValidSerialization(string preorder) {
	if(preorder == "#")
		return true;
    stack<int> status;
    int pos = 0;
    int n = preorder.length();
    bool first = true;
    while(pos < n) {
        int start = pos;
        while(pos < n && preorder[pos] != ',')
            pos++;
        string cur = preorder.substr(start, pos - start);
        if(cur == "#") {
            if(status.empty())
                return false;
            else {
                status.top()--;
                while(!status.empty() && status.top() == 0) {
                    status.pop();
                    if(!status.empty())
                        status.top()--;
                }
            }
        }
        else {
            if(status.empty() && !first)
                return false;
            else {
                status.push(2);
                first = false;
            }
        }
        pos++;
    }
    return status.empty();
}

int main() {
    string s;
    cin >> s;
    bool res = isValidSerialization(s);
    cout << res << endl;
    return 0;
}
