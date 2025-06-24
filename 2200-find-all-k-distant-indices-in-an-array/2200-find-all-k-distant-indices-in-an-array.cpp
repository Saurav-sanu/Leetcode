class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int>result;
        int start=0;
        int end=0;
        for(int j=0;j<n;j++){
            if(nums[j]==key){
                start=max(j-k,0);
                end=min(j+k,n-1);

                if(!result.empty() && result.back()>=start){
                    start=result.back()+1;
                }

                for(int i=start;i<=end;i++){
                    result.push_back(i);
                }
            }
        }
        return result;
    }
};