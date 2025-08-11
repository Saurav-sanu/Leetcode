class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        stack<int>st;
        int n=nums2.size();
        vector<int>GRE(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            if(!st.empty() && nums2[i]<=st.top()){
                GRE[i]=st.top();
            }
            st.push(nums2[i]);

        }

        int index=-1;
        for(int i=0;i<nums1.size();i++){
            int num=nums1[i];
            for(int j=0;j<nums2.size();j++){
                if(nums2[j]==num){
                    index=j;
                    break;
                }
            }
            ans.push_back(GRE[index]);  
        }
        return ans;
    }
};