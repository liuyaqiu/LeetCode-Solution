#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<string, string> urls;

    string hash(string url) {
        long long hash = 0;
        for(int i = 0; i < (int)url.length(); i++)
            hash = hash * 10 + url[i];
        return to_string(hash);
    }

public:
    string encode(string longUrl) {
        string key = hash(longUrl);
        urls[key] = longUrl;
        return key;
    }

    string decode(string shortUrl) {
        return urls[shortUrl];
    }
};

