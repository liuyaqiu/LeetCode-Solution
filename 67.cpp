#include <iostream>
#include <string>
#include <vector>

using namespace std;

void addition(char& a, const char& b, char& add) {
    int num = a - '0';
    int plus = b - '0';
    int pre = add - '0';
    a = (num + plus + pre) % 2 + '0';
    add = (num + plus + pre) / 2 + '0';
}

string addBinary(string a, string b) {
    if(a.length() < b.length())
        swap(a, b);
    auto iter_a = a.rbegin();
    auto iter_b = b.rbegin();
    char add = '0';
    while(iter_b != b.rend()) {
        addition(*iter_a, *iter_b, add);
        ++iter_a;
        ++iter_b;
    }
    while(add != '0' && iter_a != a.rend()) {
        addition(*iter_a, '0', add);
        ++iter_a;
    }
    if(add != '0')
        return "1" + a;
    else
        return a;
}

int main() {
    string a, b;
    cout << "Please input a and b: ";
    cin >> a >> b;
    string res = addBinary(a, b);
    cout << "The addition is: " << res << endl;
    return 0;
}
