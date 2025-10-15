class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0;
        int count=0;
        int maxi=INT_MIN;

        int n=nums.size();
        while(i<n){
            if(nums[i]==1){
                count++;
                i++;
            }
            else{
                maxi=max(maxi,count);
                count=0;
                i++;
            }
            
        }
        maxi=max(maxi,count);
        return maxi;
    }
};