class Solution {
public:
vector<vector<int>>direction={{0,1},{0,-1},{-1,0},{1,0}};
int DFS(vector<vector<int>>&grid,int i ,int j){
    //base case
     int m=grid.size();
    int n=grid[0].size();
    if(i<0 ||j<0 ||i>=m ||j>=n ||grid[i][j]==0){
        return 0;
    }

    int curr=grid[i][j];
    int maxGld=0;



    grid[i][j]=0;
    for(auto &dir:direction){
        int new_i=i+dir[0];
        int new_j=j+dir[1];

        maxGld=max(maxGld,DFS(grid,new_i,new_j));
    }
    grid[i][j]=curr;
    return maxGld+curr;
}

    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxGld=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]!=0){
                    maxGld=max(maxGld,DFS(grid,i,j));
                }
            }
        }
        return maxGld;
    }
};