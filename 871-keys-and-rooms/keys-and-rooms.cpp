class Solution {
public:
    int visited[1000] = {0};
    void dfs(int node, vector<vector<int>>& rooms){
        visited[node] = 1;
        for(auto child:rooms[node]){
            if(!visited[child]){
                dfs(child, rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(0, rooms);
        for(int i = 0 ; i < rooms.size(); i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};