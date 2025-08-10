class Solution {
public:
vector<vector<int>>ans;
vector<int>temp;
    void solve(vector<int>&nums,int i){
        //
        int n=nums.size();
       ans.push_back(temp);

        for(int idx=i;idx<n;idx++){
            if(idx>i && nums[idx]==nums[idx-1]){
                continue;
            }
            temp.push_back(nums[idx]);
            solve(nums, idx + 1);
            temp.pop_back();
        }


    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sort first for duplicate handling
        solve(nums,0);
        return ans;
    }
};