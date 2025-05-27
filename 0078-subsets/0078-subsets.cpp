class Solution {
public:
vector<vector<int>>result;
void solve(vector<int>&nums,vector<int>&ans,int idx){
    //base case
    if(idx==nums.size()){
       
        result.push_back(ans);
        
        return ;
    }


    ans.push_back(nums[idx]);
    solve(nums,ans,idx+1);
    ans.pop_back();

    solve(nums,ans,idx+1);


}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        solve(nums,ans,0);
        return result;
    }
};