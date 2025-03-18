class Solution {
public:
void DFS(unordered_map<int,vector<pair<int,int>>>&adj,vector<bool>&visited,int &mini,int u){
    visited[u]=true;

    for(auto &vec:adj[u]){
        int v=vec.first;
        int wt=vec.second;

        mini=min(mini,wt);

        if(!visited[v]){
            DFS(adj,visited,mini,v);
        }
    }
}
    int minScore(int n, vector<vector<int>>& roads) {
        int m=roads.size();
        unordered_map<int,vector<pair<int,int>>>adj;

        for(auto edge:roads){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        vector<bool>visited(n,false);
        int mini=INT_MAX;

        DFS(adj,visited,mini,1);

        return mini;
    }
};