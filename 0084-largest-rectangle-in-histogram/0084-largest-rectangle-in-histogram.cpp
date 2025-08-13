class Solution {
public:
    vector<int>Nsl(vector<int>&arr){
        stack<int>st;
        int n=arr.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i] <=arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int>Nsr(vector<int>&arr){
        stack<int>st;
        int n=arr.size();
        vector<int>ans(n,n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i] <arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>l=Nsl(heights);
        vector<int>r=Nsr(heights);
        int maxi=0;

        for(int i=0;i<n;i++){
            int width=r[i]-l[i]-1;
            int area=width * heights[i];
            maxi=max(maxi,area);
        }
        return maxi;
    }
};