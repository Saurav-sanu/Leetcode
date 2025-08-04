class Solution {
public:
bool binary(vector<int>&nums,int target,int start,int end){
    while(start<=end){
        int mid=start+(end-start)/2;
        if(nums[mid]==target){
            return true;
        }
        else if(nums[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return false;
}
int min(vector<int>&nums,int n){
    int l=0;
    int r=n-1;
    while(l<r && nums[l]==nums[l+1]){
        l++;
    }
    while(l<r && nums[r]==nums[r-1]){
        r--;
    }
    while(l<r){
        int mid=l+(r-l)/2;
        if(nums[mid]>nums[r]){
            l=mid+1;

        }
        else{
            r=mid;
        }
    }
    return r;
}
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivot=min(nums,n);
        bool one=binary(nums,target,0,pivot-1);
        bool two=binary(nums,target,pivot,n-1);

        return one || two;
    }
};