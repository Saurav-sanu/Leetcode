class Solution {
public:
bool dfs(vector<vector<int>>& graph,vector<int>&color,int u ,int currColor){
    //bsae case
    color[u]=currColor;

    for(auto &v:graph[u]){
        if(color[v]==color[u]){
            return false;
        }
        if(color[v]==-1){
            int newColor=1-currColor;
            if(dfs(graph,color,v,newColor)==false){
                return false;
            }
        }
    }
    return true;

}
    bool isBipartite(vector<vector<int>>& graph) {
        //using dfs
        int n=graph.size();
        vector<int>color(n,-1);
        // green - 1
        
        // red - 0

        int curr=1;

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(graph,color,i,curr)==false){
                    return false;
                }
            }
        }
        return true;

    }
};