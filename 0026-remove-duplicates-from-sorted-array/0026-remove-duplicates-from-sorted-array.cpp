class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0;
        int i=0;
        int n=nums.size();
        while(i<n){
            if(nums[i]==nums[l]){
                i++;
            }
            else{
                l++;
                nums[l]=nums[i];
            }
        }
        return l+1;
    }
};