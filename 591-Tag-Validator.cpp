/*
  Tag Validator

  Given a string representing a code snippet, you need to implement a tag validator to parse the code and return whether it is valid. A code snippet is valid if all the following rules hold:

The code must be wrapped in a valid closed tag. Otherwise, the code is invalid.

A closed tag (not necessarily valid) has exactly the following format : <TAG_NAME>TAG_CONTENT</TAG_NAME>. Among them, <TAG_NAME> is the start tag, and </TAG_NAME> is the end tag. The TAG_NAME in start and end tags should be the same. A closed tag is valid if and only if the TAG_NAME and TAG_CONTENT are valid.

A valid TAG_NAME only contain upper-case letters, and has length in range [1,9]. Otherwise, the TAG_NAME is invalid.

A valid TAG_CONTENT may contain other valid closed tags, cdata and any characters (see note1) EXCEPT unmatched <, unmatched start and end tag, and unmatched or closed tags with invalid TAG_NAME. Otherwise, the TAG_CONTENT is invalid.

A start tag is unmatched if no end tag exists with the same TAG_NAME, and vice versa. However, you also need to consider the issue of unbalanced when tags are nested.

A < is unmatched if you cannot find a subsequent >. And when you find a < or </, all the subsequent characters until the next > should be parsed as TAG_NAME (not necessarily valid).

The cdata has the following format : <![CDATA[CDATA_CONTENT]]>. The range of CDATA_CONTENT is defined as the characters between <![CDATA[ and the first subsequent ]]>.

CDATA_CONTENT may contain any characters. The function of cdata is to forbid the validator to parse CDATA_CONTENT, so even it has some characters that can be parsed as tag (no matter valid or invalid), you should treat it as regular characters.

 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

//检查CDATA标记，并讲CDATA标记去除
bool checkCDATA(string& str) {
    string start = "<![CDATA[";
    string end = "]]>";
    int pos = str.find(start, 0);
    while(pos != -1) {
        int match = str.find(end, pos);
        if(match == -1)
            return false;
        pos = str.find(start, match);
    }
    //删除所有成对的CDATA标记
    while(str.find(start, 0) != -1) {
        int p = str.find(start, 0);
        int q = str.find(end, p);
        str.replace(p, q + 3 - p, "cdata");
    }
    return true;
}

bool validTagName(string tag) {
    if(tag[0] == '/')
        tag = tag.substr(1, tag.length() - 1);
    if(tag.empty() || tag.length() > 9)
        return false;
    for(int i = 0; i < tag.length(); i++) {
        int num = tag[i] - 'A';
        if(num < 0 || num >= 26)
            return false;
    }
    return true;
}

bool checkTAG(string& str) {
    // cout << str << endl;
    stack<string> tags;
    int pos = str.find("<", 0);
    if(pos != 0)
        return false;
    int end = 0;
    while(pos != -1) {
        int match = str.find(">", pos);
        if(match == -1)
            return false;
        string tag = str.substr(pos + 1, match - pos - 1);
        // cout << tag;
        if(!validTagName(tag))
            return false;
        // cout << ": valid" << endl;
        if(tag[0] != '/') {
            if(tags.empty() && end != 0)
                return false;
            tags.push(tag);
        }
        else {
            if(tags.empty() || tags.top() != tag.substr(1, tag.length() - 1))
                return false;
            else
                tags.pop();
        }
        pos = str.find("<", match);
        end = match + 1;
    }
    return tags.empty() && end == str.length();
}

bool isValid(string code) {
    return checkCDATA(code) && checkTAG(code);
}

int main() {
    string code;
    getline(cin, code);
    if(isValid(code))
        cout << "Valid" << endl;
    else
        cout << "Invalid" << endl;
    return 0;
}
