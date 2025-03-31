class Solution {
public:
int solve(vector<int>&nums,int index){
    //base case
    if(index>=nums.size()){
        return 0;
    }

    int include=solve(nums,index+2)+nums[index];
    int exclude=solve(nums,index+1);

    return max(include,exclude);
}
    int rob(vector<int>& nums) {
        return solve(nums,0);
    }
};