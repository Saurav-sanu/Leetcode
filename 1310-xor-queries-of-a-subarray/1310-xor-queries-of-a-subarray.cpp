class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>currxor(n,0);
        currxor[0]=arr[0];
        for(int i=1;i<n;i++){
            currxor[i]=currxor[i-1]^arr[i];
        }
        vector<int>result;

        for(int i=0;i<queries.size();i++){
            int left=queries[i][0];
            int right=queries[i][1];

            int xor_val=currxor[right]^(left-1<0 ? 0:currxor[left-1]);
            result.push_back(xor_val);

        }
        return result;

    }
};