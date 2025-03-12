class Solution {
public:
vector<vector<int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
typedef pair<int,int>P;
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        queue<P>q;
        vector<vector<int>>maxHeight(m,vector<int>(n,-1));


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    maxHeight[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int size=q.size();

            while(size--){
                auto node=q.front();
                q.pop();

                int x=node.first;
                int y=node.second;

                for(auto dir:directions){
                    int new_x=x+dir[0];
                    int new_y=y+dir[1];

                    if(new_x>=0 && new_x<m && new_y>=0 && new_y<n && maxHeight[new_x][new_y]==-1){
                        maxHeight[new_x][new_y]=maxHeight[x][y]+1;
                        q.push({new_x,new_y});
                    }
                }

            }
        }

        return maxHeight;

    }
};