class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xxor=0;
        for(int num:nums){
            xxor^=num;
        }

        long long  mask=xxor & (-xxor);

        int groupa=0;
        int groupb=0;

        for(int &num:nums){
            if(mask&num){
                groupa^=num;
            }
            else{
                groupb^=num;
            }
        }
        return {groupa,groupb};
    }
};