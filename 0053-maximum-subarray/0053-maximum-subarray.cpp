class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSubarray=nums[0];
        int maxSubarray=nums[0];
        for(int i=1;i<nums.size();i++){
            currSubarray=max(nums[i],currSubarray+nums[i]);
            maxSubarray=max(maxSubarray,currSubarray);
        }
        return maxSubarray;
    }
};