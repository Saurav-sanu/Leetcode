class Solution {
public:
int candivide(vector<int>&nums,int mid){
    int div=0;
    for(auto it:nums){
        div+=(it+mid-1)/mid;
       
    }
    return div;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int e=*max_element(nums.begin(),nums.end());
        int result=0;


        while(s<=e){
            int mid=s+(e-s)/2;

            if(candivide(nums,mid)<=threshold){
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