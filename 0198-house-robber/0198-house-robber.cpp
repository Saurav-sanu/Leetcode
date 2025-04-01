class Solution {
public:
int t[101];
int solve(vector<int>&nums,int index){
    //base case
    if(index>=nums.size()){
        return 0;
    }
    if(t[index]!=-1){
        return t[index];
    }

    int include=solve(nums,index+2)+nums[index];
    int exclude=solve(nums,index+1);

    return t[index]=max(include,exclude);
}
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(nums,0);
    }
};