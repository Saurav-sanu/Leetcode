class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        for(int &num:nums){
            ans^=num;
        }
        int diff=ans^k;

        return __builtin_popcount(diff);
    }
};