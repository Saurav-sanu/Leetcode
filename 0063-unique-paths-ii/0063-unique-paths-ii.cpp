class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        //using bottom up approach
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>t(row,vector<int>(col));
         if (grid[0][0] == 1) return 0;
        t[0][0]=1;
        for(int i=1;i<col;i++){
            if(grid[0][i]==0){
                t[0][i]=t[0][i-1];
            }
            else{
                t[0][i]=0;
            }
        }
        for(int i=1;i<row;i++){
            if(grid[i][0]==0){
                t[i][0]=t[i-1][0];
            }
            else{
                t[i][0]=0;
            }
        }

        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(grid[i][j]==0){
                    t[i][j]=t[i-1][j]+t[i][j-1];
                }
            }
        }
        return t[row-1][col-1];
    }
};