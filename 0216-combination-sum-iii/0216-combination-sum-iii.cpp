class Solution {
public:
vector<vector<int>>result;
vector<int>curr;
void solve(int k,int n,int sum,int index){
    //base case
    if(k==0){
        if(sum==n){
            result.push_back(curr);
        }
        return;
    }
    if(index>9){
        return ;
    }
    if(k<0){
        return ;
    }


    //
   for(int i=index;i<=9;i++){
    curr.push_back(i);
    solve(k-1,n,sum+i,i+1);
    curr.pop_back();

   }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(k,n,0,1);
        return result;
    }
};