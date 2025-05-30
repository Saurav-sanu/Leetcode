class Solution {
public:
void solve(vector<int>&nums,int k,unordered_map<int,int>&mp,int &result,int idx){
    //base cse
    if(idx>=nums.size()){
        result++;
        return ;
    }
    //not. take
    solve(nums,k,mp,result,idx+1);

    //take
    if(!mp[nums[idx]-k] && !mp[nums[idx]+k]){
        mp[nums[idx]]++;
        solve(nums,k,mp,result,idx+1);
        mp[nums[idx]]--;
    }
}
    int beautifulSubsets(vector<int>& nums, int k) {
        int result=0;
        unordered_map<int,int>mp;
        solve(nums,k,mp,result,0);
        return result-1;
    }
};