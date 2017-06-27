#include <iostream>
#include <vector>

using namespace std;

/*
 * UTF-8 Validation
 *
 * A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:
 *
 * For 1-byte character, the first bit is a 0, followed by its unicode code.
 * For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.
 * This is how the UTF-8 encoding would work:
 *
 *    Char. number range  |        UTF-8 octet sequence
 *       (hexadecimal)    |              (binary)
 *    --------------------+---------------------------------------------
 *    0000 0000-0000 007F | 0xxxxxxx
 *    0000 0080-0000 07FF | 110xxxxx 10xxxxxx
 *    0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
 *    0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
 * Given an array of integers representing the data, return whether it is a valid utf-8 encoding.
 *
 * Note:
 * The input is an array of integers. Only the least significant 8 bits of each integer is used to store the data. This means each integer represents only 1 byte of data.
 *
 * Example 1:
 * data = [197, 130, 1], which represents the octet sequence: 11000101 10000010 00000001.
 * Return true.
 *
 * It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.
 *
 * Example 2:
 * data = [235, 140, 4], which represented the octet sequence: 11101011 10001100 00000100.
 * Return false.
 *
 * The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
 * The next byte is a continuation byte which starts with 10 and that's correct.
 * But the second continuation byte does not start with 10, so it is invalid.
 *
 *
 */

int leadingOnes(int n) {
    int zero = 0x80;
    int one = 0xC0;
    int two = 0xE0;
    int three = 0xF0;
    int four = 0xF8;
    if((n & zero) == 0)
        return 0;
    else if((n & one) == zero)
        return 1;
    else if((n & two) == one)
        return 2;
    else if((n & three) == two)
        return 3;
    else if((n & four) == three)
        return 4;
    else
        return -1;
}

bool validUtf8(vector<int>& data) {
    vector<int> cnt;
    for(auto num: data) {
        int val = leadingOnes(num);
        if(val < 0)
            return false;
        else
            cnt.push_back(val);
    }
    int pos = 0;
    int n = cnt.size();
    while(pos < n) {
        int val = cnt[pos];
        if(val == 0)
            pos++;
        else if(val == 1){
            return false;
        }
        else {
            while(val > 1 && pos + val - 1 < n) {
                if(cnt[pos + val - 1] != 1)
                    return false;
                val--;
            }
            if(val > 1)
                return false;
            pos += cnt[pos];
        }
    }
    return true;
}

int main() {
    int val;
    vector<int> data;
    while(cin >> val) {
        data.push_back(val);
    }
    int res = validUtf8(data);
    cout << res << endl;
    return 0;
}
