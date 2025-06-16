class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++){
            if(grid[i][0]==0){
                //flipping that row

                for(int j=0;j<n;j++){
                    grid[i][j]=1-grid[i][j];
                }
            }
        }

        //coulmn
        for(int j=0;j<n;j++){
            int countzero=0;
            for(int i=0;i<m;i++){
                if(grid[i][j]==0){
                    countzero++;
                }
            }
            int countone=m-countzero;


            if(countzero>countone){
                //flipping that colmn
                for(int i=0;i<m;i++){
                    grid[i][j]=1-grid[i][j];
                }
            }
        }


        int score=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                score+=grid[i][j]*(1<<(n-j-1));
            }
        }
        return score;
    }
};