class Solution {
public:
int MOD=1e9+7;
vector<int> NSL(vector<int>&arr){
    stack<int>st;
    int n=arr.size();
    vector<int>ans(n,-1);
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int>NSR(vector<int>&arr){
    stack<int>st;
    int n=arr.size();
    vector<int>ans(n,n);
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i]=st.top();
        }
        st.push(i);
    }
    return ans;
}
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>G=NSL(arr);
        vector<int>S=NSR(arr);
        long long sum=0;

        for(int i=0;i<arr.size();i++){
            long long total=0;
            long long left=i-G[i];
            long right=S[i]-i;
            total=(left*right)%MOD;

            sum+=(total*arr[i])%MOD;
        }
        return sum%MOD;
    }

};