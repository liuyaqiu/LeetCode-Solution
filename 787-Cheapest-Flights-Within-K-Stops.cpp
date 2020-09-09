class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int inf = 1e9;
        vector<int> cost(n, inf);
        cost[src] = 0;
        for (int i = 0; i <= K; i++) {
            vector<int> tmp_cost(cost);
            for (const auto& flight : flights) {
                tmp_cost[flight[1]] = min(tmp_cost[flight[1]], cost[flight[0]] + flight[2]);
            }
            cost.swap(tmp_cost);
        }
        return cost[dst] >= inf ? -1 : cost[dst];
    }
};