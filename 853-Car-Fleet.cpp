class Solution {
public:
    bool collision(const pair<int, int>& s1_v1, const pair<int ,int>& s2_v2, int target) {
        if (s1_v1.first < s2_v2.first) {
            return false;
        } else if (s1_v1.first == s2_v2.first) {
            return true;
        } else {
            if (s1_v1.second >= s2_v2.second) {
                return false;
            } else {
                double t = 1.0 * (s1_v1.first - s2_v2.first) / (s2_v2.second - s1_v1.second);
                if (s1_v1.first + t * s1_v1.second > target) {
                    return false;
                } else {
                    return true;
                }
            }
        }
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> position_and_speed;
        for (int i = 0; i < position.size(); i++) {
            position_and_speed.push_back({position[i], speed[i]});
        }
        auto compare = [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
            if (lhs.first != rhs.first) {
                return lhs.first > rhs.first;
            }
            return lhs.second < rhs.second;
        };
        sort(position_and_speed.begin(), position_and_speed.end(), compare);
        map<int, int> car_fleet;
        for (const auto& s_and_v : position_and_speed) {
            if (s_and_v.first > target) {
                continue;
            }
            auto iter = car_fleet.lower_bound(s_and_v.first);
            if (iter == car_fleet.end() || !collision(*iter, s_and_v, target)) {
                car_fleet[s_and_v.first] = s_and_v.second;
            }
        }
        return car_fleet.size();
    }
};