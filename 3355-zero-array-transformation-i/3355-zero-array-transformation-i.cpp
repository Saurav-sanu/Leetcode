class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>diff(n,0);
        for(auto q:queries){
            int s=q[0];
            int e=q[1];
            int x=1;

            diff[s]+=x;


            if(e+1<n){
                diff[e+1]-=x;
            }
        }
        vector<int>cumalative(n,0);

        // cumalative[0]=diff[0];
        // for(int i=1;i<n;i++){
        //     cumalative[i]=diff[i]+cumalative[i-1];
        // }

        int curr=0;
        for(int i=0;i<n;i++){
            curr+=diff[i];
            cumalative[i]=curr;
        }

        for(int i=0;i<n;i++){
            if(cumalative[i]<nums[i]){
                return false;
            }
        }
        return true;
    }
};