/*
 * Substring with Concatenation of All Words
 *
 * You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
 *
 * For example, given:
 * s: "barfoothefoobarman"
 * words: ["foo", "bar"]
 *
 * You should return the indices: [0,9].
 * (order does not matter).
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <string>

using namespace std;

void judgeWord(map<string, int>& words, vector<int>& array, string str, bool& judge) {
    auto iter = words.find(str);
    if(iter == words.end())
        judge = false;
    else {
        int pos = iter->second;
        if(array[pos] < 0)
            judge = false;
        else
            array[pos] -= 1;
    }
}
vector<int> getArray(vector<string>& words, map<string, int>& theWords) {
    vector<int> res(theWords.size(), 0);
    for(auto iter = words.begin(); iter != words.end(); ++iter) {
    	auto res_iter = theWords.find(*iter);
    	if(res_iter != theWords.end()) {
    		int pos = res_iter->second;
    		res[pos] += 1;
    	}
    }
    return res;
}

vector<int> findSubstring(string s, vector<string> words) {
    int len = words[0].length();
    map<string, int> theWords;
    int k = 0;
    for(int i = 0; i < words.size(); i += 1) {
    	if(theWords.find(words[i]) == theWords.end())
        	theWords.insert(pair<string, int>(words[i], k++));
    }
    vector<int> res;
    vector<int> the_array = getArray(words, theWords);
    int n = s.length() - len * int(words.size());
    cout << s.length() << endl;
    cout << n << endl;
    vector<bool> pre_sub(len, false);
    if(theWords.size() == 1 && len == 1) {
        int pos = - words.size() * len;
        for(int i = 0; i <= s.length(); i += 1) {
            if(pos >= 0)
                res.push_back(i - words.size() * len);
            string tmp = s.substr(i, len);
            if(tmp == words[0])
                pos += 1;
            else
                pos = - words.size() * len;
        }
        return res;
    }
    for(int i = 0; i <= n; i += 1) {
       	vector<int> array(the_array);
       	bool judge = true;
       	int pos = i + (words.size() - 1) * len;
       	if(pre_sub[i % len] && i >= len && pos < s.length()) {
	       	string t2 = s.substr(pos, len);
	       	string h1 = s.substr(i - len, len);
	       	if(h1 == t2){
	       		res.push_back(i);
	       		continue;
	       	}
       	}
	       	for(int j = 0; j < words.size() && judge; j += 1) {
	           string str = s.substr(i + j * len, len);
	           judgeWord(theWords, array, str, judge);
	       	}
	       	if(judge) {
	       		for(auto iter = array.begin(); iter != array.end(); ++ iter) {
	       			if(*iter != 0) {
	       				judge = false;
	       				break;
	       			}
	       		}
	       		if(judge) {
	       			res.push_back(i);
	       		}
	       	}
	       	pre_sub[i % len] = judge;
    }
    return res;
}

void printVector(vector<int> res) {
    for(auto iter = res.begin(); iter != res.end(); ++iter)
        cout << *iter<< " ";
    cout << endl;
}

int main() {
    //string s = "barfoothefoobarman";
    //string s = "a";
    //string s = "mississippi";
    //vector<string> words = {"mississippis"};
    //vector<string> words = {"a", "a"};
    //vector<string> words = {"foo", "bar"};
    //string s = "wordgoodgoodgoodbestword";
	//vector<string> words = {"word","good","best","good"};
	//string s = "foobarfoobar";
	//vector<string> words = {"foo","bar"};
	string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	vector<string> words = {"a", "a", "a", "a", "a", "a"};
	//string s = "bcccbbbcba";
	//vector<string> words = {"cc","bb"};
	//string s = "abaababbaba";
	//vector<string> words = {"ba","ab","ab"};
    vector<int> res = findSubstring(s, words);
    printVector(res);
}
