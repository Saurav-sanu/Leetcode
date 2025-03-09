class Solution {
public:
typedef pair<int,int>P;
int prims(vector<vector<P>>&adj,int V){
    vector<bool>inMst(V,false);

    priority_queue<P,vector<P>,greater<P>>pq;

    pq.push({0,0});
    int sum=0;


    while(!pq.empty()){
        auto element=pq.top();
        pq.pop();

        int dist=element.first;
        int node=element.second;

        if(inMst[node]==true){
            continue;
        }

        inMst[node]=true;
        sum+=dist;

        for(auto &ngr:adj[node]){
            int ngr_node=ngr.first;
            int ngr_dist=ngr.second;

            if(!inMst[ngr_node]){
                pq.push({ngr_dist,ngr_node});
            }
        }
    }
    return sum;

}
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<P>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt=abs(points[j][1]-points[i][1])+abs(points[j][0]-points[i][0]);

                adj[i].push_back({j,wt});
                adj[j].push_back({i,wt});
            }
        }

        return prims(adj,n);
    }
};


//using kruskal 
class Solution {
public:

vector<int>parent;
vector<int>Rank;
int find(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=find(parent[x]);
}
void Union(int x,int y){
    int parent_x=find(x);
    int parent_y=find(y);

    if(parent_x==parent_y){
        return ;
    }

    if(Rank[parent_y]<Rank[parent_x]){
        parent[parent_y]=parent_x;
    }
    else if(Rank[parent_x]<Rank[parent_y]){
        parent[parent_x]=parent_y;
    }
    else{
        parent[parent_x]=parent_y;
        Rank[parent_y]++;

    }
}

int kruskal(vector<vector<int>>&adj,int n){
    int sum=0;
    for(auto &t:adj){
        int u=t[0];
        int v=t[1];
        int wt=t[2];

        int parent_u=find(u);
        int parent_v=find(v);
        if(parent_u!=parent_v){
            Union(u,v);
            sum+=wt;
        }
    }
    return sum;
}

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        parent.resize(n);
        Rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        vector<vector<int>>adj;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt=abs(points[j][1]-points[i][1])+abs(points[j][0]-points[i][0]);

                adj.push_back({i,j,wt});
            }
        }

        auto comparator=[&](vector<int>& a,vector<int> &b){
            return a[2]<b[2];
        };

        sort(adj.begin(),adj.end(),comparator);

        return kruskal(adj,n);
    }
};
