class Solution {
public:
void solve(vector<int>& candidates, int target,vector<vector<int>>&ans,int index,vector<int>&temp){
    //base case
    if(target==0){
        ans.push_back(temp);
       
        return ;
    }
    if(target<0)return;

        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            temp.push_back(candidates[i]);
            solve(candidates,target-candidates[i],ans,i+1,temp);
            temp.pop_back();
            
        }

        



}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int index=0;
        vector<vector<int>>ans;
        vector<int>temp;

        solve(candidates,target,ans,index,temp);
        return ans;
    }
};