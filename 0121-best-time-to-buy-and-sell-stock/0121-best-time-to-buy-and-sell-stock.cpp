class Solution {
public:
    int maxProfit(vector<int>& arr) {
       int n=arr.size();
       int mini=INT_MAX;
       int maxi=0;
       for(int i=0;i<n;i++){
        mini=min(arr[i],mini);
        maxi=max(maxi,arr[i]-mini);
       }
       return maxi;
    }
};