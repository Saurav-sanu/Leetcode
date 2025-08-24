class Solution {
public:
void dfs(vector<vector<int>>& adj,int u,vector<bool>&visited){
    visited[u]=true;

        int n = adj.size();

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                dfs(adj, v, visited);
            }
        }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n=isConnected.size();
        vector<bool>visited(n,false);

        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                dfs(isConnected,i,visited);
                count++;
            }
        }

        return count;
    }
};