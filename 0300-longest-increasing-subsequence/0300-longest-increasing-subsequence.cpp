class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //using patience sorting
        int n=nums.size();
        vector<int>sorted;


        for(int i=0;i<n;i++){
            auto it=lower_bound(sorted.begin(),sorted.end(),nums[i]);

            if(it==end(sorted)){
                sorted.push_back(nums[i]);
            }
            //aasa element mil gy hai jo usse greater hai 
            else{
                *it=nums[i];
            }
        }
        return sorted.size();


    }
};