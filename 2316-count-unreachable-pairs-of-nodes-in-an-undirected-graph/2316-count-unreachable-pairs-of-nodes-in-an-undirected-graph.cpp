class Solution {
public:
void DFS(vector<bool>&visited,int u,int &size,unordered_map<int,vector<int>>&adj){
    visited[u]=true;
    size++;

    for(int &v:adj[u]){
        if(!visited[v]){
            DFS(visited,v,size,adj);
        }
    }
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        //using dfs
        long long remainingnodes=n;
        long long result=0;
        vector<bool>visited(n,false);
        unordered_map<int,vector<int>>adj;
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
                int size=0;
                DFS(visited,i,size,adj);
                result+=(size)*(remainingnodes-size);
                remainingnodes-=size;

            }
        }

        return result;

    }
};




//using DSU
vector<int>parent;
vector<int>rankA;
int find(int x){
    if(x==parent[x]){
        return x;
    }
    return parent[x]=find(parent[x]);
}

void Union(int x,int y){
    int x_parent=find(x);
    int y_parent=find(y);

    if(x_parent==y_parent){
        return;
    }
    if(rankA[x_parent]<rankA[y_parent]){
        parent[x_parent]=y_parent;
    }
    else if(rankA[y_parent]<rankA[x_parent]){
        parent[y_parent]=x_parent;
    }
    else {
        parent[y_parent]=x_parent;
        rankA[x_parent]+=1;

    }

}
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rankA.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        //step 2
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];

            Union(u,v);
        }

        unordered_map<int,int>mp;

        //step 3
        for(int i=0;i<n;i++){
            int papaji=find(i);
            mp[papaji]++;
        }


        long long result=0;
        long long remaining=n;

        for(auto &it:mp){
            int size=it.second;

            result+=(size)*(remaining-size);

            remaining-=size;

        }

        return result;
    }
};
