class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //if cycle so false
        int count=0;
        int n=numCourses;
        vector<int>indegree(numCourses,0);
        unordered_map<int,vector<int>>adj;
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

            for(auto &v:adj[node]){

                indegree[v]--;

                if(indegree[v]==0){
                    q.push(v);
                    count++;
                }
            }
        }

        if(count==n){
            return true;
        }
        return false;


        
    }
};