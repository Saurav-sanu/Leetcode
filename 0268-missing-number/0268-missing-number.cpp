class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xori=0;
        for(int i=0;i<nums.size();i++){
            xori^=nums[i];
        }
       
        for(int i=0;i<=nums.size();i++){
            xori^=i;
        }

        return xori;



    }
};