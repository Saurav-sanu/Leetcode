class Solution {
public:
int leftmost(vector<int>& nums, int target){
    int ans=-1;
    int start=0;
    int end=nums.size()-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(nums[mid]==target){
            ans=mid;
            end=mid-1;
            
        }
        else if(nums[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}
int rightmost(vector<int>& nums, int target){
    int ans=-1;
    int start=0;
    int end=nums.size()-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(nums[mid]==target){
            ans=mid;
            start=mid+1;
            
        }
        else if(nums[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=leftmost(nums,target);
        int right=rightmost(nums,target);
        vector<int>ans;
        ans.push_back(left);
        ans.push_back(right);
        
        return ans;
        
    }
};