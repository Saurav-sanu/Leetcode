class Solution {
public:
bool isSafe(int newX,int newY,vector<vector<int>>temp){
    if(newX>=0 && newY>=0 && newX<temp.size() && newY <temp[0].size() && temp[newX][newY]==1){
        return true;
    }
    else{
        return false;
    }
}
    int orangesRotting(vector<vector<int>>& grid) {
        //pair<int,int>->corrdinated
        //second member->int ->time
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>temp=grid;
        int minTime=0;

        //FIND ALL ROTTEN ORANGES AND PUTH THEN IN QUEUE
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp[i][j]==2){
                    //src node ka time 0 set krna hai

                    q.push({{i,j},0});

                }
            }
        }
        while(!q.empty()){
            auto frontNodePair=q.front();
            q.pop();
            
            auto frontNodeCoordinates=frontNodePair.first;
            int frontNodeTime=frontNodePair.second;
            int tempX=frontNodeCoordinates.first;
            int tempY=frontNodeCoordinates.second;

            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int newX=dx[i]+tempX;
                int newY=dy[i]+tempY;

                if(isSafe(newX,newY,temp)){
                    q.push({{newX,newY},frontNodeTime+1});
                    minTime=max(minTime,frontNodeTime+1);
                    //make this node as rotten
                    temp[newX][newY]=2;
                }
            }

        }
        //yah tak rotten kar diya hai
        //ab i want to check k kya maine saare orange rotten kar diye hai
        int freshOrangeCount=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp[i][j]==1){
                    return -1;
                }
            }
        }
       return minTime;

    }
};