class Solution {
public:
     vector<int> prevSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] <= nums[st.top()]) {
                st.pop();  // Pop elements until we find a smaller element
            }

            if (st.empty()) {
                ans[i] = -1;  // No smaller element to the left
            } else {
                ans[i] = st.top();  // Index of the smaller element
            }

            st.push(i);  // Push current index
        }
        return ans;
     }
    vector<int>nextSmaller(vector<int>& nums){
        int n=nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while (!st.empty() && nums[i] <= nums[st.top()]) {
                st.pop();  // Pop elements until we find a smaller element
            }

            if (st.empty()) {
                ans[i] = n;  // No smaller element to the left
            } else {
                ans[i] = st.top();  // Index of the smaller element
            }

            st.push(i);  // Push current index
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>prev=prevSmaller(heights);
        vector<int>next=nextSmaller(heights);
        int maxi=INT_MIN;

        for(int i=0;i<heights.size();i++){
            int width=next[i]-prev[i]-1;
            maxi=max(maxi,heights[i]*width);
        }

        return maxi;
    }
};