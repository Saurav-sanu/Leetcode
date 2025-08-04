class Solution {
public:
int canload(vector<int>&nums,int mid){
    int day=1;
    int currentload=0;
    for(int wt:nums){
        if(currentload+wt>mid){
            day++;
            currentload=wt;
        }
        else{
            currentload+=wt;
        }
    }
    return day;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int s=*max_element(weights.begin(),weights.end());
       int e=accumulate(weights.begin(),weights.end(),0);
       int result=e;
        while(s<=e){
            int mid=s+(e-s)/2;

            if(canload(weights,mid)<=days){
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