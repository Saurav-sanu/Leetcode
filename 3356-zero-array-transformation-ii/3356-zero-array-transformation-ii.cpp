class Solution {
public:
    bool canmake(vector<int>& nums, vector<vector<int>>& q,int k){
            int n=nums.size();
        
            vector<int>diff(n,0);
            for(int i=0;i<k;i++){
                int s=q[i][0];
                int e=q[i][1];
                int val=q[i][2];

                diff[s]+=val;

                if(e+1<n){
                    diff[e+1]-=val;
                }
            }

            vector<int>cummalative(n,0);
            int curr=0;
            for(int i=0;i<n;i++){
                curr+=diff[i];
                if(curr<nums[i]){
                    return false;
                }
            }
           
            return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m=queries.size();
        int ans=-1;

        int left=0;
        int right=m;

        while(left<=right){
            int mid=left+(right-left)/2;
            if(canmake(nums,queries,mid)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};