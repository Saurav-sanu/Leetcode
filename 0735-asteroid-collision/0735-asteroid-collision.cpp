class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        stack<int>st;
        int i=0;
        while(i<n){
            bool destroyed=false;
            if(nums[i]>0){
                st.push(nums[i]);
            }
            else{
                while(!st.empty() && st.top()>0){
                    if(st.top()>abs(nums[i])){
                        destroyed=true;
                        break;
                    }
                    else if(st.top()==abs(nums[i])){
                        st.pop();
                        destroyed=true;
                        break;
                    }
                    else{
                        st.pop();
                    }
                }
                if(!destroyed){
                    st.push(nums[i]);
                }
            }
                
            i++;
        }
        while(!st.empty()){
            int temp=st.top();
            ans.push_back(temp);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};