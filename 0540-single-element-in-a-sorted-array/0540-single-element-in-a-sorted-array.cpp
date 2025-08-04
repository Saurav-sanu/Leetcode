class Solution {
public:

    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        while(s<e){
            int mid=s+(e-s)/2;
            bool isEven;

            if((e-mid)%2==0){
                isEven=true;
            }
            else{
                isEven=false;
            }

            if(nums[mid]==nums[mid+1]){
                if(isEven){
                    //right mai hoga
                    s=mid+2;
                }
                else{
                    e=mid-1;
                }
            }
            else{
                if(isEven){
                    e=mid;
                }
                else{
                    s=mid+1;
                }
            }
        }
        return nums[s];
    }
};