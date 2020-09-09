class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int, set<int>> obstacles_by_x_axis;
        unordered_map<int, set<int>> obstacles_by_y_axis;
        for (int i = 0; i < obstacles.size(); i++) {
            int x = obstacles[i][0];
            int y = obstacles[i][1];
            if (!obstacles_by_x_axis.count(x)) {
                obstacles_by_x_axis[x] = {};
            }
            obstacles_by_x_axis[x].insert(y);
            if (!obstacles_by_y_axis.count(y)) {
                obstacles_by_y_axis[y] = {};
            }
            obstacles_by_y_axis[y].insert(x);
        }
        pair<int, int> prev_point = {0, 0};
        int directions = 4;
        int prev_direction = 0;
        int res = 0;
        for (int command : commands) {
            if (command == -2) {
                prev_direction = (prev_direction - 1 + directions) % directions;
            } else if (command == -1) {
                prev_direction = (prev_direction + 1) % directions;
            } else {
                if (prev_direction == 0) {
                    auto iter = obstacles_by_x_axis.find(prev_point.first);
                    if (iter == obstacles_by_x_axis.end()) {
                        prev_point.second += command;
                    } else {
                        auto y_iter = iter->second.upper_bound(prev_point.second);
                        if (y_iter == iter->second.end()) {
                            prev_point.second += command;
                        } else {
                            prev_point.second = min(prev_point.second + command, *y_iter - 1);
                        }
                    }
                } else if (prev_direction == 1) {
                    auto iter = obstacles_by_y_axis.find(prev_point.second);
                    if (iter == obstacles_by_y_axis.end()) {
                        prev_point.first += command;
                    } else {
                        auto x_iter = iter->second.upper_bound(prev_point.first);
                        if (x_iter == iter->second.end()) {
                            prev_point.first += command;
                        } else {
                            prev_point.first = min(prev_point.first + command, *x_iter - 1);
                        }
                    }
                } else if (prev_direction == 2) {
                    auto iter = obstacles_by_x_axis.find(prev_point.first);
                    if (iter == obstacles_by_x_axis.end()) {
                        prev_point.second -= command;
                    } else {
                        auto y_iter = iter->second.lower_bound(prev_point.second);
                        if (y_iter == iter->second.begin()) {
                            prev_point.second -= command;
                        } else {
                            y_iter--;
                            prev_point.second = max(prev_point.second - command, *y_iter + 1);
                        }
                    }
                } else {
                    auto iter = obstacles_by_y_axis.find(prev_point.second);
                    if (iter == obstacles_by_y_axis.end()) {
                        prev_point.first -= command;
                    } else {
                        auto x_iter = iter->second.lower_bound(prev_point.first);
                        if (x_iter == iter->second.begin()) {
                            prev_point.first -= command;
                        } else {
                            x_iter--;
                            prev_point.first = max(prev_point.first - command, *x_iter + 1);
                        }
                    }
                }
            }
            res = max(res, prev_point.first * prev_point.first + prev_point.second * prev_point.second);
        }
        return res;
    }
};