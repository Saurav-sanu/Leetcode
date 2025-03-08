class Solution {
public:
        
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //usign bfs
        vector<vector<int>> direction={{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        int m=grid.size();
        int n=grid[0].size();

        if(m==0 ||n==0 || grid[0][0]!=0){
            return -1;
        }
        auto isSafe=[&](int a,int b){
            return (a>=0 &&a<m&&b>=0 &&b<n);
        };


        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;


        int steps=1;

        while(!q.empty()){
            int sz=q.size();
            while(sz--){

                auto front=q.front();
                int a=front.first;
                int b=front.second;
                q.pop();

                if(a==m-1 && b==n-1){
                    return steps;
                }

                for(auto dir:direction){
                    int x_coor=a+dir[0];
                    int y_coor=b+dir[1];

                    if(isSafe(x_coor,y_coor) && grid[x_coor][y_coor]==0){
                        q.push({x_coor,y_coor});
                        grid[x_coor][y_coor]=1;
                    }
                }
            }
            steps++;


        }
        return -1;
    }
};