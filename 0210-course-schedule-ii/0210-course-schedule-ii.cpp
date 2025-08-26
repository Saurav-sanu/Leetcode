class Solution {
public:
bool hasCycle=false;
    void DFS(unordered_map<int,vector<int>>&adj,vector<bool>&inRecursion,int u,vector<bool>&visited,stack<int>&st){
        visited[u]=true;
        inRecursion[u]=true;

        for(int &v:adj[u]){
            if(inRecursion[v]==true){
                hasCycle=true;
                return ;
            }

            if(!visited[v]){
                DFS(adj,inRecursion,v,visited,st);
            }
                
        }
        st.push(u);
        inRecursion[u]=false;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<bool>inRecursion(numCourses,false);
        vector<bool>visited(numCourses,false);
        stack<int>st;

        for(auto &vec:prerequisites){
            int u=vec[0];
            int v=vec[1];

            adj[v].push_back(u);
        }

        vector<int>result;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                DFS(adj,inRecursion,i,visited,st);
            }
        }

        if(hasCycle==true){
            return {};
        }
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }


        return result;


    }
};