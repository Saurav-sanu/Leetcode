class Solution {
public:
int n;
void bfs(vector<vector<int>>&isConnected,int u,vector<bool>&visited){
    queue<int>q;
    q.push(u);
    visited[u]=true;

    while(!q.empty()){
        auto u=q.front();
        q.pop();

        for(int v=0;v<n;v++){
            if(!visited[v] && isConnected[u][v]==1){
                bfs(isConnected,v,visited);
            }
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        n=isConnected.size();
        vector<bool>visited(n,false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(isConnected,i,visited);
                count++;
            }
        }
        return count;
    }
};