class Solution {
public:
typedef pair<int,pair<int,int>>P;
vector<vector<int>>direction={{1,1},{0,1},{1,0},{-1,-1},{-1,1},{1,-1},{0,-1},{-1,0}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //USING dikhstra
        int m=grid.size();
        int n=grid[0].size();

        if(m==0 || n==0 || grid[0][0]==1){
            return -1;
        }
        
        auto isSafe=[&](int a,int b){
            return (a>=0 && b>=0 && a<m && b<n);
        };

        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;

        pq.push({0,{0,0}});
        result[0][0]=0;

        while(!pq.empty()){
            int direc=pq.top().first;
            pair<int,int>node=pq.top().second;
            pq.pop();

            int x=node.first;
            int y=node.second;

            for(auto dir:direction){
                int new_x=x+dir[0];
                int new_y=y+dir[1];

                int dist=1;


                if(isSafe(new_x,new_y) && grid[new_x][new_y]==0 && dist+direc<result[new_x][new_y]){
                    pq.push({dist+direc,{new_x,new_y}});
                    result[new_x][new_y]=direc+dist;
                }
            }
        }

        if(result[m-1][n-1]==INT_MAX){
            return -1;
        }

        return result[m-1][n-1]+1; 

        
    }
};