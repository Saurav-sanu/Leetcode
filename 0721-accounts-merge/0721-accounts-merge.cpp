class Solution {
public:
vector<int>parent;
vector<int>rank;
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

    if(rank[parent_x]<rank[parent_y]){
        parent[parent_x]=parent_y;
    }
    else if(rank[parent_x]>rank[parent_y]){
        parent[parent_y]=parent_x;
    }
    else {
        parent[parent_y]=parent_x;
        rank[parent_x]++;
    }
}

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();

        parent.resize(n,0);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        unordered_map<string,int>mapMail;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];

                if(mapMail.find(email)!=mapMail.end()){
                    Union(i,mapMail[email]);
                }
                else{
                    mapMail[email]=i;
                }
            }
        }
       

        unordered_map<int,vector<string>>mergedMail;
        for(auto it:mapMail){
            string node=it.first;
            int parentIndex=find(it.second);
            mergedMail[parentIndex].push_back(node);
        }

        // Step 3: Construct result
       vector<vector<string>>result;
       for(auto it:mergedMail){
            vector<string>account;
            account.push_back(accounts[it.first][0]);
            sort(it.second.begin(),it.second.end());
            

            /*
            Before Insertion:

                account: ["John"]

                it.second: ["john@example.com", "john2@example.com", "john3@example.com"]

                Insertion Process:

                The insert method starts at the end of account (account.end()).

                It then copies each element from it.second (emails) into account, starting from the end of account.

                After Insertion:

                account: ["John", "john@example.com", "john2@example.com", "john3@example.com"]
            */
            account.insert(account.end(),it.second.begin(),it.second.end());

            result.push_back(account);

       }
       return result;

    }
};