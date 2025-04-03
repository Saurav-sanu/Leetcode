class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        for(int i=0;i<row;i++){
            for(int j=1;j<col;j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }


        int result=0;
        for(int startcol=0;startcol<col;startcol++){

            for(int j=startcol;j<col;j++){

                unordered_map<int,int>mp;
                mp.insert({0,1});
                int currSum=0;
                for(int rw=0;rw<row;rw++){
                    currSum+=matrix[rw][j]-(startcol>0?matrix[rw][startcol-1]:0);

                    if(mp.find(currSum-target)!=mp.end()){
                        result+=mp[currSum-target];
                    }

                    mp[currSum]++;
                }
            }
        }
        return result;
    }
};