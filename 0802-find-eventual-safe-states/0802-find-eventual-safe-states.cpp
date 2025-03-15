class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
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