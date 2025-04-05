//using rescutsion LIS
class Solution {
public:
long long solve(int prev,int index,vector<int>&nums){
    //base case
    if(index>=nums.size()){
        return 0;
    }
    int take=0;
    if(prev==-1 ||nums[prev]-prev<=nums[index]-index){
        take=nums[index]+solve(index,index+1,nums);

    }
    int skip=solve(prev,index+1,nums);
    return max(take,skip);

}
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int maxElement=*max_element(nums.begin(),nums.end());
        if(maxElement<=0){
            return maxElement;
        }
        return solve(-1,0,nums);
    }
};

//USING BOTTOM UP OF LIS
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n=nums.size();

        int maxElement=*max_element(nums.begin(),nums.end());

        if(maxElement<=0){
            return maxElement;
        }

        vector<long long>t(n);
        for(int i=0;i<n;i++){
            t[i]=nums[i];
        }

        long long maxSum=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]-i>=nums[j]-j){
                    t[i]=max<long long>(t[i],t[j]+nums[i]);
                    maxSum=max(maxSum,t[i]);
                }
            }
        }
        return maxSum>maxElement?maxSum:maxElement;
    }
};





class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        map<int,long long>mp;
        int n=nums.size();
        long long result=INT_MIN;
        for(int i=0;i<n;i++){
            auto it=mp.upper_bound(nums[i]-i);
            long long sum=nums[i];

            if(it!=mp.begin()){
                it--;
                sum+=it->second;
            }

            mp[nums[i]-i]=max(mp[nums[i]-i],sum);

            it=mp.upper_bound(nums[i]-i);

            while(it!=mp.end() && it->second<=sum){
                mp.erase(it++);
            }

            result=max(result,sum);

        }
        return result;
    }
};
