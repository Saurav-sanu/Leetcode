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



//using bfs
class Solution {
public:
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
void BFS(int i,int j,vector<vector<int>>& grid,int &parameter){

    if(grid[i][j]==-1){
        return ;
    }
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int>>q;
    q.push({i,j});
    grid[i][j]=-1;
    

        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int x=node.first;
            int y=node.second;

                for(auto dir:directions){
                    int new_x=x+dir[0];
                    int new_y=y+dir[1];

                    if(new_x<0 || new_x>=n || new_y<0 ||new_y>=m || grid[new_x][new_y]==0){
                        parameter++;
                    }
                    else if(grid[new_x][new_y]==-1){
                        continue;
                    }
                    else{

                        grid[new_x][new_y]=-1;
                        q.push({new_x,new_y});
                    }
                }
        }
}

    int islandPerimeter(vector<vector<int>>& grid) {
        //using bfs
        int n=grid.size();
        int m=grid[0].size();

        int parameter=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    BFS(i,j,grid,parameter);

                }
            }
        }

        return parameter;
    }
};
