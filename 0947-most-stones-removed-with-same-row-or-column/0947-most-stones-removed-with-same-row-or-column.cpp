class Solution {
public:
//using DFS
void DFS(vector<vector<int>>&stones,vector<bool>&visited,int u){
    visited[u]=true;

    for(int i=0;i<stones.size();i++){
        int r=stones[u][0];
        int c=stones[u][1];
        if(!visited[i] && (stones[i][0]==r ||stones[i][1]==c)){
            DFS(stones,visited,i);
        }
    }
}
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int group=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==true){
                continue;
            }
            DFS(stones,visited,i);
            group++;
        }
        return n-group;
    }
};