#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    queue<int> surplus;
    int n = gas.size();
    for(int i = 0; i < n; i++) {
        surplus.push(gas[i] - cost[i]);
    }
    int start = 0;
    int sum = 0;
    queue<int> visit;
    while(start < n) {
        if(sum >= 0) {
        	if(surplus.empty())
        		break;
            int cur = surplus.front();
            sum += cur;
            visit.push(cur);
            surplus.pop();
        }
        else {
            int head = visit.front();
            sum -= head;
            surplus.push(head);
            visit.pop();
            start += 1;
        }
    }
    if(start < n)
        return start;
    else
        return -1;
}

int main() {
    int x, y;
    vector<int> gas, cost;
    while(cin >> x >> y) {
        gas.push_back(x);
        cost.push_back(y);
    }
    int res = canCompleteCircuit(gas, cost);
    cout << "The valid start station is: " << res << endl;
    return 0;
}
