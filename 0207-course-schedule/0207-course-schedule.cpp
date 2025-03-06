class Solution {
public:
bool toposort(unordered_map<int,vector<int>>&adj,vector<int>&indegree,int n){
    //step 1
    int count=0;

    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int top=q.front();
        count++;
        q.pop();

        for(int &v:adj[top]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }

        }

    }

    if(count==n){
        return true;
    }
    else{
        return false;
    }

}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //agar cycle hua toh fasle other wise not false;
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);

        for(auto &vec:prerequisites){
            int u=vec[0];
            int v=vec[1];

            adj[v].push_back(u);

            indegree[u]++;
        }


        return toposort(adj,indegree,numCourses);

    }
};