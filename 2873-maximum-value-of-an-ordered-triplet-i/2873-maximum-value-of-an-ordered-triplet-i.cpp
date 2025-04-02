class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n);
        vector<int>right(n);

        left[0]=0;
        for(int i=1;i<n;i++){
            left[i]=max(left[i-1],nums[i-1]);
        }

        right[n-1]=0;
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],nums[i+1]);
        }

        long long result=0;
        for(int i=0;i<n;i++){
            result=max(result,(long long)(left[i]-nums[i])*right[i]);
        }
        return result;
    }
};