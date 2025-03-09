class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {

        unordered_map<int,int>indegree,outdegree;
        unordered_map<int,vector<int>>adj;
        stack<int>st;

        for(auto &temp:pairs){
            int u=temp[0];
            int v=temp[1];

            adj[u].push_back(v);

            indegree[v]++;
            outdegree[u]++;
        }

        int startnode=pairs[0][0];
        for(auto &it:adj){
            int node=it.first;
            if((outdegree[node]-indegree[node])==1){
                startnode=node;
                break;
            }
        }

        vector<int>Eulerpath;

        st.push(startnode);

        while(!st.empty()){
            int curr=st.top();

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

        //building the path
        reverse(Eulerpath.begin(),Eulerpath.end());
        vector<vector<int>>ans;
        for(int i=0;i<Eulerpath.size()-1;i++){
            ans.push_back({Eulerpath[i],Eulerpath[i+1]});
        }

        return ans;
    }
};