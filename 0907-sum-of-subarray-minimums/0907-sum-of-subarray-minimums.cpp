class Solution {
public:
vector<int>getNSL(vector<int>&arr){
    int n=arr.size();

    stack<int>st;
    vector<int>ans(n);

//index dall rhe

    for(int i=0;i<n;i++){
        if(st.empty()){
             ans[i]=-1;
        }
        else{
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
        }
        st.push(i);
    }
    return ans;
}
vector<int>getNSR(vector<int>&arr){
    int n=arr.size();

    stack<int>st;
    vector<int>ans(n);

//index dall rhe

    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            ans[i]=n;
        }
        else{
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=st.top();
            }
        }
        st.push(i);
    }
    return ans;
}
    int sumSubarrayMins(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        vector<int>left=getNSL(arr);
        vector<int>right=getNSR(arr);
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            // Calculate frequency of arr[i] as a minimum in subarrays
            int freq = (i - left[i]) * (right[i] - i);
            sum = (sum + (long)arr[i] * freq) % mod;  // Add arr[i] * freq to the total sum
        }
        return sum;
    }
};