class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int k=j+1;
                int e=n-1;

                //two sum strategy
                while(k<e){
                    long long sum=(long long)target-nums[i]-nums[j];
                    if((long long) nums[k]+nums[e] >sum){
                        e--;
                    }
                    else if((long long )nums[k]+nums[e]<sum){
                        k++;
                    }
                    else{

                        
                        while(k<e && nums[k]==nums[k+1]){
                            k++;
                        }
                        while(k<e && nums[e]==nums[e-1]){
                            e--;
                        }

                        result.push_back({nums[i],nums[j],nums[k],nums[e]});
                        k++;
                        e--;
                        
                    }
                    
                }

            }
        }
        return result;
    }
};