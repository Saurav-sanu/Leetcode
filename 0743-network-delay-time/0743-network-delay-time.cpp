class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //solving using bfs and dikstra 
        //dikstra is kind of bfs as similar approiach is following in bfs and dikstra
        vector<int>result(n+1,INT_MAX);
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto edge:times){
            int u=edge[0];
            int v=edge[1];
            int time=edge[2];

            adj[u].push_back({v,time});
        }
        result[k]=0;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        //source ,cost
        q.push({k,0});

        while(!q.empty()){
            auto node=q.top();
            q.pop();

            int srcnode=node.first;
            int timetaken=node.second;

            for(auto vec:adj[srcnode]){
                int anothernode=vec.first;
                int tm=vec.second;

                if(timetaken+tm<result[anothernode]){
                    result[anothernode]=timetaken+tm;
                    q.push({anothernode,timetaken+tm});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(ans,result[i]);
        }
        return ans==INT_MAX?-1:ans;

    }
};
