class Solution {
public:
vector<vector<int>>result;
vector<int>curr;
void solve(vector<int>&nums,int idx){
    //base case
    if(curr.size()>=2){
        result.push_back(curr);
    }

    unordered_set<int>st;
    for(int i=idx;i<nums.size();i++){
        if((curr.empty() || nums[i]>=curr.back()) && (st.find(nums[i])==st.end())){

            curr.push_back(nums[i]);
            solve(nums,i+1);
            curr.pop_back();

            st.insert(nums[i]);
        }
    }


}
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        solve(nums,0);
        return result;
    }
};