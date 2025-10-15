class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int diff=n/2;

        for(auto dif:mp){
            if(dif.second>diff){
                ans=dif.first;
            }
        }
        return ans;
    }
};