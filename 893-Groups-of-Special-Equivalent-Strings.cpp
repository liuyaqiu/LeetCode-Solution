class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_map<string, int> group_to_size;
        for (const string& str : A) {
            string even;
            string odd;
            for (int i = 0; i < str.length(); i++) {
                if (i % 2 == 0) {
                    even += str[i];
                } else {
                    odd += str[i];
                }
            }
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            string group = even + odd;
            if (group_to_size.count(group)) {
                group_to_size[group] = 0;
            }
            group_to_size[group] += 1;
        }
        return group_to_size.size();
    }
};