class Solution {
public:
int binary(vector<int>&nums,int target,int start,int end){
    while(start<=end){
        int mid=start+(end-start)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return -1;
}
int min(vector<int>&nums,int n){
    int l=0;
    int r=n-1;
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
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivot=min(nums,n);
        int one=binary(nums,target,0,pivot-1);
        if(one!=-1){
            return one;
        }
        int two=binary(nums,target,pivot,n-1);
        return two;
    }
};