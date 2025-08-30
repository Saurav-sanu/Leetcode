class Solution {
public:
int N;
vector<vector<int>>direction={{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1},{0,1},{0,-1}};
typedef pair<int,pair<int,int>>p;
bool valid(int x,int y){
   return (x >= 0 && y >= 0 && x < N && y < N);
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue<p,vector<p>,greater<p>>pq;
        int n=grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        N=n;
        int ans=0;

       vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = 1; 

        pq.push({1,{0,0}});

        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();

            int dista=temp.first;
            int x_val=temp.second.first;
            int y_val=temp.second.second;
            if(x_val==n-1 && y_val==n-1){
                return dista;
            }

            for(auto &dir:direction){
                int new_x=x_val+dir[0];
                int new_y=y_val+dir[1];

                if(valid(new_x,new_y) && grid[new_x][new_y]==0 && dista+1<dist[new_x][new_y]){
                  
                    dist[new_x][new_y]=dista+1;
                    pq.push({dista+1,{new_x,new_y}});

                }
            }

        }
        return -1;

    }
};