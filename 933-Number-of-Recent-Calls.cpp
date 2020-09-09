class RecentCounter {
public:
    RecentCounter() {
    }

    int ping(int t) {
        while (!ping_time.empty() && ping_time.front() < t - 3000) {
            ping_time.pop();
        }
        ping_time.push(t);
        return ping_time.size();
    }

private:
    queue<int> ping_time;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */