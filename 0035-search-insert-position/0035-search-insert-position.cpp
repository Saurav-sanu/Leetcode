class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans=0;
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                end=mid-1;
            }
            else{
                ans=mid+1;
                start=mid+1;
            }
        }
        return ans;
    }
};