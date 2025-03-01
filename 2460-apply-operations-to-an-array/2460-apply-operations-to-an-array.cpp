class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(i+1<nums.size() && nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
             
            if(nums[i]!=0){
                if(j!=i){
                    swap(nums[j],nums[i]);
                }
                j++;
            }


        }
        return nums;
    }
};