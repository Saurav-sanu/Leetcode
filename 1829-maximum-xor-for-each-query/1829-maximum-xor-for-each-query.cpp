class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int>result(n);
        int XOR=0;
        for(int i=0;i<nums.size();i++){
            XOR^=nums[i];
        }

        //finding the mask
        int mask=((1<<maximumBit)-1);

        for(int i=0;i<nums.size();i++){
            int ans=XOR^mask;

            result[i]=(ans);
            XOR=XOR^nums[n-i-1];
        }
        return result;
    }
};