class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> map;
        int res = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                int prod = nums[i] * nums[j];
                map[prod]++;
            }
        }
        for(pair<int,int> m:map){
            int n=m.second;
            res += (n*(n-1))/2;
        }
        return res*8; 
    }
};