class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        bool isEven=false;
        bool isOdd=false;

        while(s<e){
            int mid=s+(e-s)/2;

            if((e-mid)%2==0){
                isEven=true;
            }
            else{
                isEven=false;
            }

            if(nums[mid]==nums[mid+1]){
                if(isEven){
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