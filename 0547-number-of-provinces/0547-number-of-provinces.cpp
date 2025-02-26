class Solution {
public:
void dfs(unordered_map<int,vector<int>>&adjList,vector<bool>&visited,int u){
    visited[u]=true;

    for(int &v:adjList[u]){
        if(!visited[v]){
            dfs(adjList,visited,v);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>visited(n,false);

        unordered_map<int,vector<int>>adjList;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int count=0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adjList,visited,i);
                count++;
            }
        }

        return count;
    }
};