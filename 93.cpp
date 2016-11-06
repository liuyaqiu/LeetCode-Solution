#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

/*
 * 本问题的策略为记录每一个小节的起始地址，使用一个vector来记录，记录为逆序的，例如对于25525511135的一种情况，起始地址为11,8,6,3,0，对应的IP为255.255.11.135
 * 回溯策略为，首先将s.lenght(), s.length() - 1置入vector中
 * 若vector的size为4时，vector的最后一个元素不等于0（没有使用完全部字符串，不能完成对应），则将vector的最后一个元素-1（向前移动一位）
 * 若vector的最后一个元素与其前一个元素的差值大于3或者当前小节字符串的解析结果大于255，说明当前小节不能再继续向前扩充，将vector的最后一个元素移除，然后将新的vector
 * 的最后一个元素-1，继续执行以上的策略。
 * 若vector的size为4，且最后一个元素等于0（此时使用了全部字符串，而且发生了一次可行的对应），则将vector对应的IP地址记录，然后移除vector最后一个元素，将新的vector的
 * 最后一个元素-1，继续执行以上策略。
 * 若vector的size小于4，若pos.back()为0（此时字符串已经用完，但是未能得到有效的IP），则将pos.back()移除，将pos.back() - 1;否则，则将pos.back() - 1置入到vector中。
 * 当vector为空时，结束回溯
 */
int toInteger(string num) {
    stringstream ss;
    ss << num;
    int res;
    ss >> res;
    return res;
}

string getIP(string s, vector<int>& pos) {
    string ip;
    for(auto iter = pos.rbegin(); iter != pos.rend() - 1; ++iter) {
    	string tmp = s.substr(*iter, *(iter + 1) - *iter);
    	if(tmp.length() > 1 && tmp[0] == '0')
    		return "";
        if(iter + 1 != pos.rend() - 1)
            ip += tmp + ".";
        else
            ip += tmp;
    }
    return ip;
}

void printpos(vector<int>& pos) {
    for(auto iter = pos.begin(); iter != pos.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

vector<string> restoreIpAddress(string s) {
	vector<string> res;
	if(s.length() < 4)
		return res;
    vector<int> pos;
    pos.push_back(s.length());
    pos.push_back(s.length() - 1);
    while(true) {
        printpos(pos);
        if(pos.size() == 1)
            break;
        int start = pos.back(), end = pos[pos.size() - 2];
        if(end - start > 3 || toInteger(s.substr(start, end - start)) > 255) {
            pos.pop_back();
            pos.back() -= 1;
            continue;
        }
        if(pos.size() == 5) {
            if(pos.back() == 0) {
            	string cur = getIP(s, pos);
            	if(!cur.empty())
            		res.push_back(cur);
                pos.pop_back();
                pos.back() -= 1;
            }
            else {
                pos.back() -= 1;
            }
        }
        else {
            if(pos.back() == 0) {
                pos.pop_back();
                pos.back() -= 1;
            }
            else
                pos.push_back(pos.back() - 1);
        }
    }
    return res;
}

void print(vector<string>& res) {
    for(auto iter = res.begin(); iter != res.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}

int main() {
    string str;
    cout << "input string: ";
    cin >> str;
    vector<string> res = restoreIpAddress(str);
    print(res);
    return 0;
}
