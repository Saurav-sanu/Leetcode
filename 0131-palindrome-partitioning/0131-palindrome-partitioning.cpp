class Solution {
public:
void solve(string &s,int i, vector<string>&partition,vector<vector<bool>>&t,vector<vector<string>>&result){

    //base case
    if(i==s.length()){
        result.push_back(partition);
        return ;
    }

    for(int j=i;j<s.length();j++){
        if(t[i][j]==true){
            partition.push_back(s.substr(i,j-i+1));
            solve(s,j+1,partition,t,result);
            partition.pop_back();
        }
    }


}
    vector<vector<string>> partition(string s) {
        //using blueprint of palindrome 
        int n=s.length();
        vector<vector<bool>>t(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            t[i][i]=true;
        }

        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(s[i]==s[j]){
                    if(l==2){
                        t[i][j]=true;
                    }
                    else{
                        t[i][j]=t[i+1][j-1];
                    }
                }
            }
        }

        vector<vector<string>>result;
        vector<string>partition;
        solve(s,0,partition,t,result);

        return result;

    }
};