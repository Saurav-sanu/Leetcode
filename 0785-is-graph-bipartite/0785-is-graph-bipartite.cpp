class Solution {
public:
    bool DFS(int u,vector<int>&Color,vector<vector<int>>&graph,int currColor){
        Color[u]=currColor;

        for(int &v:graph[u]){
            if(Color[v]==Color[u]){
                return false;
            }

            if(Color[v]==-1){
                int newColor=1-currColor;

                if(DFS(v,Color,graph,newColor)==false){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>Color(n,-1);

        for(int i=0;i<n;i++){
            if(Color[i]==-1){
                if(DFS(i,Color,graph,1)==false){
                    return false;
                }
            }
        }
        return true;
    }
};