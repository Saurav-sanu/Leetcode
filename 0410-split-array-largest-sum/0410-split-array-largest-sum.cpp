class Solution {
public:
bool ispossible(vector<int>&nums,int mid,int k){
    int count=1;
    int sum=0;
    for(auto it:nums){
       
        if(sum+it>mid){
            count++;
            sum=it;
        }
        else{
            sum+=it;
        }
    }
    return count<=k;
}
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int s=*max_element(nums.begin(),nums.end());
        int e=accumulate(nums.begin(),nums.end(),0);

        int result=-1;
        while(s<=e){
            int mid=s+(e-s)/2;

            if(ispossible(nums,mid,k)){
                result=mid;
                e=mid-1;

            }
            else{
                s=mid+1;
            }
        }
        return result;
    }
};