#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

/*
 * Longest Absolute File Path
 *
 * Suppose we abstract our file system by a string in the following manner:
 *
 * The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
 *
 * dir
 *     subdir1
 *     subdir2
 *         file.ext
 * The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.
 *
 * The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:
 *
 * dir
 *     subdir1
 *         file1.ext
 *     subsubdir1
 *         subdir2
 *             subsubdir2
 *                 file2.ext
 * The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.
 *
 * We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).
 *
 * Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.
 *
 * Note:
 * The name of a file contains at least a . and an extension.
 * The name of a directory or sub-directory will not contain a ..
 * Time complexity required: O(n) where n is the size of the input string.
 *
 * Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
 *
 *
 */

bool isFile(string s) {
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '.')
            return true;
    }
    return false;
}

int lengthLongestPath(string input) {
    if(input.empty())
        return 0;
    vector<string> path;
    vector<int> depth;
    int sum = 0;
    int pos = 0;
    int n = input.length();
    int res = 0;
    while(pos < n) {
        int cnt = 0;
        while(pos < n && input[pos] == '\t') {
            pos++;
            cnt++;
        }
        int start = pos;
        while(pos < n && input[pos] != '\n')
            pos++;
        string cur = input.substr(start, pos - start);
        int val = cur.length();
        if(depth.empty()) {
            if(isFile(cur))
                return val;
            depth.push_back(cnt);
            path.push_back(cur);
            sum += val;
        }
        else {
            while(!depth.empty() && cnt <= depth.back()) {
                sum -= path.back().length();
                depth.pop_back();
                path.pop_back();
            }
            if(isFile(cur)) {
                res = max(res, sum + val + int(path.size()));
            }
            else {
            	depth.push_back(cnt);
            	path.push_back(cur);
            	sum += val;
            }
        }
        pos++;
    }
    return res;
}

int main() {
    string input;
    input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    int res = lengthLongestPath(input);
    cout << res << endl;
    return 0;
}
