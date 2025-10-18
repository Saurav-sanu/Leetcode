class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        int n=in.size();
        sort(in.begin(),in.end());
        vector<vector<int>>ans;

        int i=0;
        int j=i+1;
        while(j<n){
            int cs=in[i][0];
            int ce=in[i][1];

            int ns=in[j][0];
            int ne=in[j][1];

            //overlapping condition
            if(ce>=ns){
                
                ce=max(ne,ce);
                in[i]={cs,ce};
            }
            else{
                ans.push_back({cs,ce});
                i=j;
                
            }
            j++;

        }

        ans.push_back(in[i]);
        return ans;

    }
};