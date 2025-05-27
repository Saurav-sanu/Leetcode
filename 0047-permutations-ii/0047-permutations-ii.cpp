class Solution {
public:
vector<vector<int>>result;
void solve(vector<int>&nums,int idx){
    //base case
    if(idx==nums.size()){
        result.push_back(nums);
        return ;
    }
    unordered_set<int>st;

    for(int i=idx;i<nums.size();i++){

        if(st.find(nums[i])!=st.end()){
            continue;
        }

        st.insert(nums[i]);
        swap(nums[i],nums[idx]);
        solve(nums,idx+1);
        swap(nums[i],nums[idx]);
        // st.erase(nums[i]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(nums,0);
        return result;
    }
};