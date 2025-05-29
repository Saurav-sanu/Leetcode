class Solution {
public:
int t[201][1001];
int solve(int index,int target,vector<int>&nums){
    //base case
    if(index>=nums.size() || target<0){
        return 0;
    }
    if(target==0){
        return 1;
    }
    if(t[index][target]!=-1){
        return t[index][target];
    }
     
    // int include=solve(0,target-nums[index],nums);
    // int exclude=solve(index+1,target,nums);
    // return t[index][target]=include+exclude;
    int result=0;
    for(int i=index;i<nums.size();i++){
        int take_i=solve(0,target-nums[i],nums);
        result+=take_i;
    }

    return t[index][target]=result;
    
}
    int combinationSum4(vector<int>& nums, int target) {
        memset(t,-1,sizeof(t));
        return solve(0,target,nums);
    }
};