class Solution {
public:
void DFS(vector<bool>&visited,int u,int &size,unordered_map<int,vector<int>>&adj){
    visited[u]=true;
    size++;

    for(int &v:adj[u]){
        if(!visited[v]){
            DFS(visited,v,size,adj);
        }
    }
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        //using dfs
        long long remainingnodes=n;
        long long result=0;
        vector<bool>visited(n,false);
        unordered_map<int,vector<int>>adj;
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
                int size=0;
                DFS(visited,i,size,adj);
                result+=(size)*(remainingnodes-size);
                remainingnodes-=size;

            }
        }

        return result;

    }
};