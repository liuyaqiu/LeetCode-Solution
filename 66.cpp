#include <iostream>
#include <string>
#include <vector>

using namespace std;

void myplus(int& num, int& add) {
    int a = num, b = add;
    num = (a + b) % 10;
    add = (a + b) / 10;
}

vector<int> plusOne(vector<int>& digits) {
    auto iter = digits.rbegin();
    int add = 1;
    while(add != 0 && iter != digits.rend()) {
        myplus(*iter, add);
        ++iter;
    }
    if(add != 0)
        digits.insert(digits.begin(), add);
    return digits;
}

void print(vector<int>& nums) {
    for(auto iter = nums.begin(); iter != nums.end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Please input the number: ";
    cin >> n;
    int val;
    vector<int> digits;
    while(n > 0) {
        cin >> val;
        digits.push_back(val);
        n -= 1;
    }
    print(digits);
    vector<int> res = plusOne(digits);
    print(res);
    return 0;
}
