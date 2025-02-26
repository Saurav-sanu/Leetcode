class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        //usig kadane algorithms

        int n=nums.size();

        int currSubSum=nums[0];
        int maxSubSum=nums[0];

        for(int i=1;i<n;i++){
            currSubSum=max(nums[i],currSubSum+nums[i]);
            maxSubSum=max(currSubSum,maxSubSum);
        }


        int minSubSum=nums[0];
        currSubSum=nums[0];
        for(int i=1;i<n;i++){
            currSubSum=min(nums[i],currSubSum+nums[i]);
            minSubSum=min(currSubSum,minSubSum);
        }


        return max(maxSubSum,abs(minSubSum));

        

    }
};