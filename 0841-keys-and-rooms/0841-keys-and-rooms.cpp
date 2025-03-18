class Solution {
public:
    void DFS(vector<vector<int>>& rooms,int u,vector<bool>&visited){
        visited[u]=true;

        for(auto &node:rooms[u]){
            if(!visited[node]){
                DFS(rooms,node,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);

        DFS(rooms,0,visited);

        for(int i=0;i<n;i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
};