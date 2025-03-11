class Solution {
public:

pair<int,int>BFS(unordered_map<int,vector<int>>adj,int source){
    queue<int>q;
    q.push(source);
    unordered_map<int,bool>visited;
    visited[source]=true;
    int distance=0;
    int farthestNode=source;

    while(!q.empty()){
        int size=q.size();

        while(size--){
            int node=q.front();

            q.pop();

            farthestNode=node;

            for(auto &ngr:adj[node]){
                if(visited[ngr]==false){
                    q.push(ngr);
                    visited[ngr]=true;
                }
            }
        }

        if(!q.empty()){
            distance++;
        }
    }

    return {farthestNode,distance};
}

int findDiameter(unordered_map<int,vector<int>>adj){
    auto[farthestNode,distance]=BFS(adj,0);

    auto[otherNode,diameter]=BFS(adj,farthestNode);
    
    return diameter;
}


    unordered_map<int,vector<int>>buildAdj(vector<vector<int>>& edges){
        unordered_map<int,vector<int>>adj;
        for(auto vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>>adj1=buildAdj(edges1);
        unordered_map<int,vector<int>>adj2=buildAdj(edges2);

        int d1=findDiameter(adj1);
        int d2=findDiameter(adj2);

        int combined=(d1+1)/2+(d2+1)/2+1;

        return max({d1,d2,combined});
    }
};