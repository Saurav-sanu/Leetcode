class Solution {
public:
void dfs(vector<vector<int>>isConnected,vector<bool>&visited,int u){
    visited[u]=true;
    int n=isConnected.size();

    for(int v=0;v<n;v++){
        if(!visited[v] && isConnected[u][v]==1){
            dfs(isConnected,visited,v);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visited(n,false);

        
        int count=0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(isConnected,visited,i);
                count++;
            }
        }

        return count;
    }
};