#include <iostream>
#include <vector>

using namespace std;

/*
 * Queue Reconstruction by Height
 *
 * Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
 *
 * Note:
 * The number of people is less than 1,100.
 *
 * Example
 *
 * Input:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 *
 * Output:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 *
 *
 */
string select(string num, int k) {
    if(k == 0)
        return "";
    int n = num.length();
    if(k == n)
        return num;
    else {
        int pos = 0;
        for(int i = 0; i <= n - k; i++) {
            if(num[i] < num[pos])
                pos = i;
        }
        return num[pos] + select(num.substr(pos + 1, n - pos - 1), k - 1);
    }
}

string removeKdigits(string num, int k) {
    string res = select(num, num.size() - k);   
    int pos = 0;
    int n = res.length();
    while(pos < n && res[pos] == '0')
        pos++;
    if(pos < n)
        return res.substr(pos, n - pos);
    else
        return "0";
}

int main() {
    string num;
    int k;
    cin >> num >> k;
    string res = removeKdigits(num, k);
    cout << res << endl;
    return 0;
}
