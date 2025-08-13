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

vector<int>getNGL(vector<int>&arr){
    int n=arr.size();

    stack<int>st;
    vector<int>ans(n);

//index dall rhe

    for(int i=0;i<n;i++){
        if(st.empty()){
             ans[i]=-1;
        }
        else{
            while(!st.empty() && arr[st.top()]<=arr[i]){
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
vector<int>getNGR(vector<int>&arr){
    int n=arr.size();

    stack<int>st;
    vector<int>ans(n);

//index dall rhe

    for(int i=n-1;i>=0;i--){
        if(st.empty()){
            ans[i]=n;
        }
        else{
            while(!st.empty() && arr[st.top()]<arr[i]){
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
    long long subArrayRanges(vector<int>& nums) {
        vector<int>leftMIN=getNSL(nums);
        vector<int>rightMIN=getNSR(nums);
        vector<int>rightMAX=getNGR(nums);
        vector<int>leftMAX=getNGL(nums);
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            long long leftMin=i-leftMIN[i],rightMin=rightMIN[i]-i;
            long long leftMax=i-leftMAX[i],rightMax=rightMAX[i]-i;

            sum+=(leftMax* rightMax-leftMin*rightMin)*nums[i];
        }
        return sum;
    }
};