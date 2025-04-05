class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int last_chosen_index=0;
        vector<int>t(n,1);
        vector<int>prevIndex(n,-1);
        int maxi=INT_MIN;
        //using bottom up approach
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    t[j]=max(t[i],t[j]+1);
                    maxi=max(maxi,t[i]);
                    prevIndex[i]=j;

                    last_chosen_index=i;

                }
            }
        }
        vector<int>result;
        while(last_chosen_index!=-1){
            result.push_back(nums[last_chosen_index]);
            last_chosen_index=prevIndex[last_chosen_index];
        }

        return result;
    }
};