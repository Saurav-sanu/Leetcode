class Solution {
public:
void solve(vector<int>nums,vector<int>&result,vector<vector<int>>&ans,int i){
    if(i==nums.size()){
        ans.push_back(result);
        return;
    }
    result.push_back(nums[i]);
    solve(nums,result,ans,i+1);
    result.pop_back();
    solve(nums,result,ans,i+1);
    
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>result;
        solve(nums,result,ans,0);
        return ans;
    }
};