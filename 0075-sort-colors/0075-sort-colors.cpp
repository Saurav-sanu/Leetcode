class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int l=0;
        int r=nums.size()-1;
        int n=nums.size();
        while(i<n && i<=r){
            if(nums[i]==2){
                swap(nums[i],nums[r]);
                r--;
                // i++;
            }
            else if(nums[i]==0){
                swap(nums[i],nums[l]);
                l++;
                i++;
              
            }
            else{
                i++;
            }

        }
        
    }
};