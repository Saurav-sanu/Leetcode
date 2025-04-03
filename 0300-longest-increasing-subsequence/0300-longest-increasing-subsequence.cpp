class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //using bootom up appracoh
        int n=nums.size();
        vector<int>t(n,1);

        int maxLis=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    t[i]=max(t[i],t[j]+1);
                    maxLis=max(maxLis,t[i]);

                }
            }
        }
        return maxLis;

    }
};