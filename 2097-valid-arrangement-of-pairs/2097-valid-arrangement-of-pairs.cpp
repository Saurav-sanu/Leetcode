class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>indegree,outdegree;
        for(auto &edge:pairs){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }
        int startNode=pairs[0][0];

        for(auto &it:adj){
            int node=it.first;
            if((outdegree[node]-indegree[node])==1){
                startNode=node;
                break;
            }
        }
        vector<int>Eulerpath;
        stack<int>st;
        st.push(startNode);

        while(!st.empty()){
            auto curr=st.top();
            
            if(!adj[curr].empty()){
                int ngbr=adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            }
            else{
                Eulerpath.push_back(curr);
                st.pop();
            }


        }
        //building the reulrt
        reverse(Eulerpath.begin(),Eulerpath.end());
        vector<vector<int>>ans;
        for(int i=0;i<Eulerpath.size()-1;i++){
            ans.push_back({Eulerpath[i],Eulerpath[i+1]});
        }
        return ans;
    }
};