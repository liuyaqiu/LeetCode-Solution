/*
  Remove Comments

  Given a C++ program, remove comments from it. The program source is an array where source[i] is the i-th line of the source code. This represents the result of splitting the original source code string by the newline character \n.

  In C++, there are two types of comments, line comments, and block comments.

  The length of source is in the range [1, 100].
  The length of source[i] is in the range [0, 80].
  Every open block comment is eventually closed.
  There are no single-quote, double-quote, or control characters in the source code.

 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> removeComments(vector<string>& source) {
    vector<string> res;
    bool block = false;
    string before_block = "";
    int before_pos = 0;
    int i = 0;
    while(i < source.size()) {
        string line = source[i];
        if(block) {
            int pos = line.find("*/", before_pos);
            before_pos = 0;
            if(pos == -1)
                i++;
            else {
                string after_block = line.substr(pos + 2, line.length() - pos - 2);
                string cur = before_block + after_block;
                if(!cur.empty())
                    source[i] = cur;
                else
                    i++;
                before_block = "";
                block = false;
            }
        }
        else {
            int pos1 = line.find("/*");
            int pos2 = line.find("//");
            bool block_comment = false;
            bool line_comment = false;
            int pos = -1;
            if(pos1 != -1) {
                if(pos2 != -1 && pos2 < pos1) {
                    line_comment = true;
                    pos = pos2;
                }
                else {
                    block_comment = true;
                    pos = pos1;
                }
            }
            else {
                if(pos2 != -1) {
                    line_comment = true;
                    pos = pos2;
                }
            }
            if(line_comment) {
                string cur = line.substr(0, pos);
                if(!cur.empty())
                    res.push_back(cur);
                i++;
            }
            if(block_comment) {
                before_block = line.substr(0, pos);
                before_pos = pos + 2;
                block = true;
            }
            if(!line_comment && !block_comment) {
                res.push_back(line);
                i++;
            }
        }
    }
    return res;
}
