class Solution {
public:
    void DFS(const vector<vector<int>>& rooms, vector<bool>& visited, int index) {
        if (index < 0 || index >= rooms.size() || visited[index]) {
            return;
        }
        visited[index] = true;
        for (int next_room : rooms[index]) {
            DFS(rooms, visited, next_room);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        DFS(rooms, visited, 0);
        int count = 0;
        for (bool visit : visited) {
            count += visit;
        }
        return count == rooms.size();
    }
};