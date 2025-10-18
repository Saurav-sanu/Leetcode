class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int n=nums.size();
        int e=n-1;

        while(l<=e){

            int mid=l+(e-l)/2;
            if(nums[mid]>target){
                e=mid-1;
            }
            else if(nums[mid]<target){
                l=start+1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};