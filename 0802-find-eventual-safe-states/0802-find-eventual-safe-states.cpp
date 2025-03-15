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

//using bfs

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //using kahn algo and using bfs
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>inDegree(n,0);
        queue<int>q;

        for(int u=0;u<n;u++){
            for(int &v:graph[u]){
                adj[v].push_back(u);
                inDegree[u]++;
            }
        }

        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }

        vector<bool>isSafe(n,false);

        while(!q.empty()){
            int node=q.front();
            isSafe[node]=true;

            q.pop();

            for(auto &v:adj[node]){
                inDegree[v]--;
                if(inDegree[v]==0){
                    q.push(v);
                }

            }
        }

        vector<int>safeNode;
        for(int i=0;i<n;i++){
            if(isSafe[i]==true){
                safeNode.push_back(i);
            }
        }

        return safeNode;
    }
};
