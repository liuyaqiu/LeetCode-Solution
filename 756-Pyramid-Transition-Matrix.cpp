/*
  Pyramid Transition Matrix

  We are stacking blocks to form a pyramid. Each block has a color which is a one letter string, like `'Z'`.

  For every block of color `C` we place not in the bottom row, we are placing it on top of a left block of color `A` and right block of color `B`. We are allowed to place the block there only if `(A, B, C)` is an allowed triple.

  We start with a bottom row of bottom, represented as a single string. We also start with a list of allowed triples allowed. Each allowed triple is represented as a string of length 3.

  Return true if we can build the pyramid all the way to the top, otherwise false.

  Example 1:
  Input: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
  Output: true
  Explanation:
  We can stack the pyramid like this:
  A
  / \
  D   E
  / \ / \
  X   Y   Z

  This works because ('X', 'Y', 'D'), ('Y', 'Z', 'E'), and ('D', 'E', 'A') are allowed triples.
  Example 2:
  Input: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
  Output: false
  Explanation:
  We can't stack the pyramid to the top.
  Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.
  Note:
  bottom will be a string with length in range [2, 8].
  allowed will have length in range [0, 200].
  Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.

 */

#include <iosteram>
#include <vector>
#include <map>

using namespace std;

bool solve(string bottom, map<string, vector<string>>& refer) {
    if(bottom.length() < 2)
        return true;
    vector<string> nextLevel = neighbors(bottom, refer);
    for(auto new_b: nextLevel) {
        if(solve(new_b, refer))
            return true;
    }
    return false;
}

vector<string> generate(int k, vector<vector<string>>& replace, const vector<string>& pre) {
    if(k >= replace.size())
        return pre;
    vector<string> res;
    for(auto item: pre) {
        for(auto cur: replace[k])
            res.push_back(item + cur);
    }
    return generate(k + 1, replace, res);
}

vector<string> neighbors(string bottom, map<string, vector<string>>& refer) {
    vector<vector<string>> replace;
    for(int i = 0; i < bottom.length() - 1; i++) {
        string cur = bottom.substr(i, 2);
        if(refer.find(cur) == refer.end())
            return {};
        else
            replace.push_back(refer[cur]);
    }
    vector<string> res = generate(0, replace, {""});
    return res;
}

bool pyramidTransition(string bottom, vector<string>& allowed) {
    map<string, vector<string>> refer;
    for(auto line: allowed) {
        if(refer.find(line.substr(0, 2)) == refer.end())
            refer[line.substr(0, 2)] = {};
        refer[line.substr(0, 2)].push_back(line.substr(2, 1));
    }
    return solve(bottom, refer);
}
