class Solution {
public:
typedef pair<int,pair<int,int>>P;
vector<vector<int>>direction={{1,1},{1,-1},{-1,1},{-1,-1},{0,1},{0,-1},{1,0},{-1,0}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();
        if(m==0 ||n==0 ||grid[0][0]!=0){
            return -1;
        }
        auto isSafe=[&](int a,int b){
            return (a>=0 && a<m && b>=0 &&b<n);
        };


        //using dijkastra algo
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>q;
        result[0][0]=0;
        q.push({0,{0,0}});

        while(!q.empty()){
           int d=q.top().first;
           auto &front=q.top().second;
           int x=front.first;
           int y=front.second;
           q.pop();

            for(auto dir:direction){
                int x_dir=x+dir[0];
                int y_dir=y+dir[1];
                int dist=1;
                if(isSafe(x_dir,y_dir) && grid[x_dir][y_dir]==0 && d+dist<result[x_dir][y_dir]){
                    q.push({d+dist,{x_dir,y_dir}});
                    result[x_dir][y_dir]=d+dist;
                }
            }



        }
        if(result[m-1][n-1]==INT_MAX){
            return -1;
        }
        return result[m-1][n-1]+1;

    }
};



//using dikstar using priority _queue
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
