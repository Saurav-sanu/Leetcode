class Solution {
public:
int solve(int j,int k ,vector<int>&arr,unordered_map<int,int>&mp){
    int target=arr[k]-arr[j];

    if(mp.find(target)!=mp.end() && mp[target]<j){
        int i=mp[target];
        return solve(i,j,arr,mp)+1;
    }
    return 2;
}
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        int max_length=0;
        for(int j=1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int length=solve(j,k,arr,mp);
                if(length>=3){
                    max_length=max(length,max_length);
                }
            }
        }
        return max_length;
    }
};

here time is 0(n^3)
space is 0(n)//recursion ka stack use ho rha hia isliye.



//using memmoiszation 
time is o(n^2)
space is 0(n) recusion stack ka space hai woh 

class Solution {
public:
int solve(int j,int k ,vector<int>&arr,unordered_map<int,int>&mp,vector<vector<int>>&t){
    if(t[j][k]!=-1){
        return t[j][k];
    }
    int target=arr[k]-arr[j];

    if(mp.find(target)!=mp.end() && mp[target]<j){
        int i=mp[target];
        return t[j][k]=solve(i,j,arr,mp,t)+1;
    }
    return t[j][k]=2;
}
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        vector<vector<int>>t(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        int max_length=0;
        for(int j=1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int length=solve(j,k,arr,mp,t);
                if(length>=3){
                    max_length=max(length,max_length);
                }
            }
        }
        return max_length;
    }
};
