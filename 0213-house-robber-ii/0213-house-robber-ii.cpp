//using top down approach
class Solution {
public:
int t[101];
int solve(vector<int>&nums,int index,int n){
    //base case
    if(index>n){
        return 0;
    }
    if(t[index]!=-1){
        return t[index];
    }

    int take=nums[index]+solve(nums,index+2,n);
    int skip=solve(nums,index+1,n);

    return t[index]=max(skip,take);
}
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        int n=nums.size();

        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        int taking0th_house=solve(nums,0,n-2);
        memset(t,-1,sizeof(t));
        int taking1th_house=solve(nums,1,n-1);

        return max(taking0th_house,taking1th_house);
    }
};



//using bottom up appraoch

class Solution {
public:
    int rob(vector<int>& nums) {
        //using bottom up
        int n=nums.size();
        vector<int>t(n+1,-1);

        if(n==1){
            return nums[0];
        }

        //case 1
        t[0]=0;

        for(int i=1;i<=n-1;i++){
            int take=nums[i-1]+(i-2>=0?t[i-2]:0);
            int skip=t[i-1];

            t[i]=max(skip,take);

        }
        int result1=t[n-1];

        t.clear();

        // case 2
        t[0]=0;
        t[1]=0;

        for(int i=2;i<=n;i++){
            int take=nums[i-1]+(i-2>=0?t[i-2]:0);
            int skip=t[i-1];
            t[i]=max(skip,take);

        }
        int result2=t[n];

        return max(result1,result2);

    }
};
