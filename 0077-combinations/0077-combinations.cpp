class Solution {
public:
vector<vector<int>>result;
vector<int>curr;
void solve(int n,int k,int idx){
    //base casa
    if(k==0){
        result.push_back(curr);
        return;
    }
    if(idx>n){
        return ;
    }


    curr.push_back(idx);
    solve(n,k-1,idx+1);
    curr.pop_back();

    solve(n,k,idx+1);
}
    vector<vector<int>> combine(int n, int k) {
        solve(n,k,1);

        return result;
    }
};