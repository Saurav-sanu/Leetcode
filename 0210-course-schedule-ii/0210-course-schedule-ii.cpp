class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         int count=0;
        int n=numCourses;
        vector<int>indegree(numCourses,0);
        unordered_map<int,vector<int>>adj;
        vector<int>result;
        for(auto &vec:prerequisites){
            int u=vec[0];
            int v=vec[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            result.push_back(node);

            for(auto &v:adj[node]){

                indegree[v]--;

                if(indegree[v]==0){
                    q.push(v);
                    count++;
                }
            }
        }

        if(count==n){
            return result;
        }
        return {};
    }
};