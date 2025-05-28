class Solution {
public:
int m,n;
int nonObstacle;
int result;
vector<vector<int>>direction={{1,0},{-1,0},{0,1},{0,-1}};
    void backtrack(vector<vector<int>>&grid,int i,int j,int count){
    //base cas
        if(i<0 || j<0 || i==m ||j==n ||grid[i][j]==-1){
            return ;
        }
        if(grid[i][j]==2){
            if(count==nonObstacle){
                result++;

            }
            return;
        }

        grid[i][j]=-1;

        for(auto &dir:direction){
            int new_i=i+dir[0];
            int new_j=j+dir[1];

            backtrack(grid,new_i,new_j,count+1);
        }


        grid[i][j]=0;


    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        result=0;
        nonObstacle=0;
        int start_x,start_y=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    nonObstacle++;
                }
                if(grid[i][j]==1){
                    start_x=i;
                    start_y=j;
                }

            }
        }
        nonObstacle++;
        int count=0;
        backtrack(grid,start_x,start_y,count);
        return result;
    }
};