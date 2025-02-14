class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int i=0;
        int j=0;
        int sum=0;
        int ans=0;
        int countzero=0;
        int n=nums.size();
        while(j<n){
            sum+=nums[j];

            while(i<j && (nums[i]==0 || sum>goal)){
                if(nums[i]==0){
                    countzero++;
                }
                else{
                    countzero=0;
                }
                sum-=nums[i];
                i++;
            }
            if(sum==goal){
                ans+=1+countzero;
            }
            j++;
        }
        return ans;
    }
};