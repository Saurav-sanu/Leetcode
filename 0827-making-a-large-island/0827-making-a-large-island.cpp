class Solution {
public:

vector<vector<int>>direction={{1,0},{-1,0},{0,1},{0,-1}};
int dfs(vector<vector<int>>& grid,int x,int y,int id){
    int n=grid.size();

    int count=1;

    grid[x][y]=id;

    for(auto dir:direction){
        int new_x=x+dir[0];
        int new_y=y+dir[1];

        if(new_x>=0 && new_x<n &&new_y >=0 && new_y<n && grid[new_x][new_y]==1 ){
            count+=dfs(grid,new_x,new_y,id);
            
        }
    }
    return count;

}
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int maxarea=0;
        int id=2;
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j]==1){
                    int size=dfs(grid,i,j,id);
                    maxarea=max(maxarea,size);
                    mp[id]=size;
                    id++;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int>Unique_id;
                    for(auto dir:direction){
                        int i_=dir[0]+i;
                        int j_=dir[1]+j;

                        if(i_>=0 && i_<n && j_>=0 && j_<n && grid[i_][j_]!=0){
                            Unique_id.insert(grid[i_][j_]);
                        }
                    }

                    int overallsize=1;
                    for(auto &it:Unique_id){
                        overallsize+=mp[it];
                    }
                    maxarea=max(maxarea,overallsize);
                }
            }
        }
        return maxarea==0?(n*n):maxarea;
    }
};