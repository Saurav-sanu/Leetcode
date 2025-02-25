class Solution {
public:
    unordered_map<int,vector<int>>adjList;
    unordered_map<int,int>BobMap;
    int aliceAmount;


    bool DFSBob(int curr,int t,vector<int>&visited){

        visited[curr]=true;
        BobMap[curr]=t;

        if(curr==0){
            return true;
        }

        for(auto & nbr:adjList[curr]){
            if(!visited[nbr]){
               if( DFSBob(nbr,t+1,visited)==true){
                    return true;
               }
            }
        }
        BobMap.erase(curr);
        return false;


    }

    void DFSAlice(int curr,int t,int income,vector<int>&visited,vector<int>&amount){
        visited[curr]=true;

        if(BobMap.find(curr)==BobMap.end() || t<BobMap[curr]){
            income+=amount[curr];
        }
        else if(t==BobMap[curr]){
            income+=amount[curr]/2;
        }

        if(adjList[curr].size()==1){
            aliceAmount=max(aliceAmount,income);
        }

        for(int &ngbr:adjList[curr]){
            if(!visited[ngbr]){
                DFSAlice(ngbr,t+1,income,visited,amount);
            }
        }

    }


    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        aliceAmount=INT_MIN;

        int time=0;

        
        for(vector<int>&vec:edges){
            int u=vec[0];
            int v=vec[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<int>visited(n,false);
        DFSBob(bob,time,visited);

        int income=0;
        visited.assign(n,false);

        DFSAlice(0,0,income,visited,amount);

        return aliceAmount;

    }
};