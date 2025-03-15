class Solution {
public:
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};

void DFS(vector<vector<bool>>&visited,int row,int col,vector<vector<char>>& grid,int n,int m){
    visited[row][col]=true;

    for(auto dir:directions){
        int new_r=row+dir[0];
        int new_c=col+dir[1];

        if(new_r>=0 && new_c>=0 && new_r<n && new_c<m && visited[new_r][new_c]==false && grid[new_r][new_c]=='1'){
            DFS(visited,new_r,new_c,grid,n,m);
        }
    }
}

    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    DFS(visited,i,j,grid,n,m);
                }
            }
        }
        return count;
    }
};