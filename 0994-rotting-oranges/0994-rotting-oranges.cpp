class Solution {
public:
typedef pair<int,int>P;
vector<vector<int>>direction={{0,1},{1,0},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<P>q;
        int freshOranges=0;
        int minutes=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    freshOranges++;
                }
            }
        }
        if(freshOranges==0){
            return 0;
        }

        while(!q.empty()){
            int size=q.size();

            while(size--){
                auto node=q.front();
                q.pop();

                int x_corr=node.first;
                int y_corr=node.second;

                for(auto dir:direction){
                    int new_x=dir[0]+x_corr;
                    int new_y=dir[1]+y_corr;

                    if(new_x>=0 && new_y>=0 && new_x<m && new_y<n && grid[new_x][new_y]==1){
                        grid[new_x][new_y]=2;
                        q.push({new_x,new_y});
                        freshOranges--;
                    }

                }

            }
            minutes++;

        }
        return freshOranges==0?minutes-1:-1;

    }
};