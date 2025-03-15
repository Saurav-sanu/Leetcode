class Solution {
public:
bool DFS(vector<bool>&visited,vector<bool>&inRecursion,int u,vector<vector<int>>& graph){
    //using dfs
    visited[u]=true;
    inRecursion[u]=true;

    for(auto v:graph[u]){
        if(visited[v]==false && DFS(visited,inRecursion,v,graph)){
            return true;
        }
        if(inRecursion[v]==true && visited[v]==true){
            return true;
        }

    }

    inRecursion[u]=false;
    return false;

}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //using dfs 
        int n=graph.size();
        vector<bool>inRecursion(n,false);
        vector<bool>visited(n,false);


        for(int i=0;i<n;i++){
            if(!visited[i]){
                DFS(visited,inRecursion,i,graph);
            }
        }
        vector<int >ans;

        for(int i=0;i<inRecursion.size();i++){
            if(inRecursion[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};