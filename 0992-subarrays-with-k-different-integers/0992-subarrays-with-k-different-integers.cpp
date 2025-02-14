class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int i_bada=0;
        int result=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        while(j<n){
            mp[nums[j]]++;

            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
                i_bada=i;
            }
            while(mp[nums[i]]>1){
                //shiringing

                mp[nums[i]]--;
                i++;
            }
            if(mp.size()==k){
                result+=(i-i_bada + 1 );
            }
            j++;
        }
        return result;
    }
};