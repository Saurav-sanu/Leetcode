class Solution {
public:
vector<vector<int>>result;
void solve(vector<int>&nums,int idx){
    //base case
    if(idx==nums.size()){
        result.push_back(nums);
        return;
    }

    for(int i=idx;i<nums.size();i++){
        swap(nums[i],nums[idx]);
        solve(nums,idx+1);
        //backtracking
        swap(nums[i],nums[idx]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
       
        solve(nums,0);
        return result;
    }
};