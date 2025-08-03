class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int count=0;

        for(int j=0;j<nums.size();j++){

            if(nums[j]==1){
                count++;
                ans=max(ans,count);
            }
            else{
                count=0;
            }
        }
        return ans;
    }
};