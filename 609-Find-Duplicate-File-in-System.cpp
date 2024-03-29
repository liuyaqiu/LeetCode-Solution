/*
  Find Duplicate File in System

  Given a list of directory info including directory path, and all the files with contents in this directory, you need to find out all the groups of duplicate files in the file system in terms of their paths.

A group of duplicate files consists of at least two files that have exactly the same content.

A single directory info string in the input list has the following format:

"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"

It means there are n files (f1.txt, f2.txt ... fn.txt with content f1_content, f2_content ... fn_content, respectively) in directory root/d1/d2/.../dm. Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.

The output is a list of group of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:

"directory_path/file_name.txt"

Example 1:
Input:
["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
Output:
[["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
Note:
No order is required for the final output.
You may assume the directory name, file name and file content only has letters and digits, and the length of file content is in the range of [1,50].
The number of files given is in the range of [1,20000].
You may assume no files or directories share the same name in the same directory.
You may assume each given directory info represents a unique directory. Directory path and file info are separated by a single blank space.

 */

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<string> resolve(string path) {
    int pos = 0;
    int end = path.find(' ', pos);
    string dir = path.substr(pos, end - pos);
    vector<string> result;
    pos = end + 1;
    end = path.find(' ', pos);
    while(end != -1) {
        string name = path.substr(pos, end - pos);
        pos = end + 1;
        end = path.find(' ', pos);
        result.push_back(dir + '/' + name);
    }
    result.push_back(dir + '/' + path.substr(pos, path.length() - pos));
    return result;
}

vector<vector<string>> findDuplicate(vector<string>& paths) {
    map<string, vector<string>> contents;
    vector<vector<string>> res;
    for(auto path: paths) {
        vector<string> tmp = resolve(path);
        for(auto file: tmp) {
            int pos = file.find('(');
            int end = file.length() - 1;
            string name = file.substr(0, pos);
            string content = file.substr(pos + 1, end - pos - 1);
            if(contents.find(content) != contents.end())
                contents[content].push_back(name);
            else
                contents[content] = {name};
        }
    }
    for(auto item: contents) {
        if(item.second.size() > 1)
            res.push_back(item.second);
    }
    return res;
}
