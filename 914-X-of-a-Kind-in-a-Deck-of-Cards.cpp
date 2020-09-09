int gcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    while (a % b != 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return b;
}

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> deck_to_count;
        for (int num : deck) {
            if (!deck_to_count.count(num)) {
                deck_to_count[num] = 0;
            }
            deck_to_count[num] += 1;
        }
        int max_cards = deck_to_count.begin()->second;
        for (const auto& deck_and_count : deck_to_count) {
            max_cards = gcd(deck_and_count.second, max_cards);
            if (max_cards < 2) {
                return false;
            }
        }
        return true;
    }
};