class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int n=nums.size();
        int e=n-1;

        while(l<=e){

            int mid=l+(e-l)/2;
            if(nums[mid]>target){
                e--;
            }
            else if(nums[mid]<target){
                l++;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};