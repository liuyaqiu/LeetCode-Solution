#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <typeinfo>
using namespace std;

string convert(string s, int numRows) {
	if(numRows == 1)
		return s;
    char res[s.length()];
    int pos = 0;
    for(int i = 1; i <= numRows; i++) {
    	int j = i;
    	int delta0 = 2 * (numRows - i), delta1 = 2 * (i - 1);
    	int count = 0;
    	while(j <= s.length()) {
    		res[pos] = s[j - 1];
    		if(count % 2 == 0) {
    			j += delta0;
    			if(delta0 > 0)
    				pos++;
    		}
    		else {
    			j += delta1;
    			if(delta1 > 0)
    				pos++;
    		}
    		count += 1;
    	}
    }
    string res_str(&res[0], &res[s.length()]);
    return res_str;
}

int main() {
	string s;
	int n;
	cout<<"Please input the string and numRows: ";
	cin>>s;
	cin>>n;
	cout<<convert(s, n)<<endl;
	return 0;
}