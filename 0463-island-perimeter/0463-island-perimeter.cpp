class Solution {
public:
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
void DFS(int i,int j,vector<vector<int>>& grid,int &parameter){
    int n=grid.size();
    int m=grid[0].size();
    if(i<0 || i>=n || j<0 ||j>=m ||grid[i][j]==0){
        parameter++;
        return ;
    }

    if(grid[i][j]==-1){
        return ;
    }
    grid[i][j]=-1;

    DFS(i-1,j,grid,parameter);
    DFS(i,j-1,grid,parameter);
    DFS(i+1,j,grid,parameter);
    DFS(i,j+1,grid,parameter);
}

    int islandPerimeter(vector<vector<int>>& grid) {
        //using dfs
        int n=grid.size();
        int m=grid[0].size();

        int parameter=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){

                    DFS(i,j,grid,parameter);

                }
            }
        }

        return parameter;
    }
};