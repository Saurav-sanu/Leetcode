class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //ager cycle hua toh false wrna 
        // kahn' algo

        vector<int>result;
        int count=0;
        queue<int>q;
        vector<int>indegree(numCourses,0);

        unordered_map<int,vector<int>>adj;
        for(auto &vec:prerequisites){
            int u=vec[0];
            int v=vec[1];

            adj[v].push_back(u);
            indegree[u]++;
        }

        //step 2
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
                result.push_back(i);
            }
        }

        //step 3
        while(!q.empty()){
            int top=q.front();
            q.pop();

            for(int &v:adj[top]){
                indegree[v]--;
                if(indegree[v]==0){
                    count++;
                    result.push_back(v);
                    q.push(v);
                }
            }
        }

        if(count==numCourses){
            return result;
        }
        else{
            return {};
        }

    }
};