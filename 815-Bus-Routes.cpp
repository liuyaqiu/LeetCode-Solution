class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        unordered_map<int, vector<int>> stop_to_buses;
        for (int i = 0; i < routes.size(); i++) {
            for (int j : routes[i]) {
                if (stop_to_buses.find(j) == stop_to_buses.end()) {
                    stop_to_buses[j] = {};
                }
                stop_to_buses[j].push_back(i);
            }
        }
        vector<bool> stop_visited(1000000 + 1, false);
        queue<int> current_level;
        int count = 0;
        current_level.push(S);
        stop_visited[S] = true;
        queue<int> next_level;
        vector<bool> bus_visited(routes.size(), false);
        while (!current_level.empty()) {
            int top = current_level.front();
            if (top == T) {
                return count;
            }
            current_level.pop();
            for (int bus : stop_to_buses[top]) {
                if (bus_visited[bus]) {
                    continue;
                }
                bus_visited[bus] = true;
                for (int stop : routes[bus]) {
                    if (!stop_visited[stop]) {
                        stop_visited[stop] = true;
                        next_level.push(stop);
                    }
                }
            }
            if (current_level.empty()) {
                swap(current_level, next_level);
                count += 1;
            }
        }
        return -1;
    }
};