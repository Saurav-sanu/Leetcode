class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        unordered_map<int,int> mp;

        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        int diff = n/3;

        for(auto dif : mp){
            if(dif.second > diff){
                ans.push_back(dif.first);
            }
        }

        return ans;
    }
};