class Solution {
public:
vector<vector<int>>result;
    void twosum(int target,vector<int>&nums,int s,int e){
        int i=s;
        int j=e;

        while(i<j){
            if(nums[i]+nums[j]>target){
                j--;
            }
            else if(nums[i]+nums[j]<target){
                i++;
            }
            else{

                while(i<j&& nums[i]==nums[i+1]){
                    i++;
                }
                while(i<j && nums[j]==nums[j-1]){
                    j--;
                }
                result.push_back({-target,nums[i],nums[j]});

                i++;
                j--;
            }
           

        }


    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return {};
        }
        sort(nums.begin(),nums.end());
        result.clear();

        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int target=nums[i];

            twosum(-target,nums,i+1,n-1);

        }
        return result;
    }
};