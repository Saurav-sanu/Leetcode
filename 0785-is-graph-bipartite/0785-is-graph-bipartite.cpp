class Solution {
public:
bool BFS(vector<vector<int>>&graph,vector<int>&Color,int u,int currColor){
    queue<int>q;
    q.push(u);
    Color[u]=currColor;

    while(!q.empty()){
        int u=q.front();
        q.pop();

        for(auto &v:graph[u]){
            if(Color[v]==Color[u]){
                return false;
            }
            if(Color[v]==-1){
                Color[v]=1-Color[u];
                q.push(v);
            }
        }
    }
    return true;


}
    bool isBipartite(vector<vector<int>>& graph) {
        //suign BFS
        int n=graph.size();
        vector<int>Color(n,-1);

        for(int i=0;i<n;i++){
            if(Color[i]==-1){
                if(BFS(graph,Color,i,1)==false){
                    return false;
                }
            }
        }
        return true;

    }
};