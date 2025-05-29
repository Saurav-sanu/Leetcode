class Solution {
public:
int t[201][1001];
int solve(vector<int>&nums,int target,int idx){
    if(target==0){
        return 1;

    }
    if(idx>=nums.size() || target<0){
        return 0;
    }
    if(t[idx][target]!=-1){
        return t[idx][target];
    }

    int take=solve(nums,target-nums[idx],0);
    int nottake=solve(nums,target,idx+1);
    return t[idx][target]=take+nottake;
}

    int combinationSum4(vector<int>& nums, int target) {
        memset(t,-1,sizeof(t));
        return solve(nums,target,0);

    }
};