class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>distance(n,INT_MAX);
        unordered_map<int,vector<pair<int,int>>>adj(n);
        for(auto edge:flights){
            int u=edge[0];
            int v=edge[1];
            int cost=edge[2];

            adj[u].push_back({v,cost});
        }

        distance[src]=0;
        queue<pair<int,int>>q;
        //source,cost
        q.push({src,0});
        int steps=0;

        while(!q.empty() && steps<=k){
            int size=q.size();

            while(size--){

                auto node=q.front();
                q.pop();
                

                int sorc=node.first;
                int cst=node.second;

                for(auto vec:adj[sorc]){
                    int anothercost=vec.second;
                    int destkindnode=vec.first;

                    if(cst+anothercost<distance[destkindnode]){
                        distance[destkindnode]=cst+anothercost;
                        q.push({destkindnode,cst+anothercost});
                    }

                }
            }
            steps++;
        }
        return distance[dst]==INT_MAX?-1:distance[dst];
    }
};