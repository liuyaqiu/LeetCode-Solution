class Solution {
public:
    vector<pair<string, int>> getSubdomain(string domain) {
        int pos_space = domain.find(' ');
        string cnt = domain.substr(0, pos_space);
        int pos = pos_space;
        vector<pair<string, int>> res;
        while (pos < domain.length() && pos != -1) {
            res.push_back(make_pair(domain.substr(pos + 1, domain.length() - pos - 1), stoi(cnt)));
            pos = domain.find('.', pos + 1);
        }
        return res;
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> res;
        for (string domain : cpdomains) {
            for (const auto& pair : getSubdomain(domain)) {
                if (!res.count(pair.first)) {
                    res[pair.first] = 0;
                }
                res[pair.first] += pair.second;
            }
        }
        vector<string> unique;
        for (const auto& pair : res) {
            unique.push_back(to_string(pair.second) + " " + pair.first);
        }
        return unique;
    }
};