class Solution {
public:
    void DFS(vector<vector<int>>& graph,int u,int target,vector<vector<int>>&result,vector<int>&ans){
        ans.push_back(u);

        if(u==target){
            result.push_back(ans);
        }
        else{
            for(auto ngr:graph[u]){
                DFS(graph,ngr,target,result,ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        int target=n-1;
        int source=0;
        vector<vector<int>>result;
        vector<int>ans;

        DFS(graph,source,target,result,ans);

        return result;

    }
};