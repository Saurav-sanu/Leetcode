class Solution {
public:
vector<vector<int>>result;
void solve(int k,int n,vector<int>&temp,int index){
    //base case
    if(k==0 && n==0){
        result.push_back(temp);
        return;
    }

    if(index>9){
        return;
    }
    if(k<0){
        return ;
    }

// both should wrong fine


    // temp.push_back(index);
    // solve(k-1,n-index,temp,index+1);
    // temp.pop_back();
    // solve(k,n,temp,index+1);


    //dusra 

    for(int i=index;i<=9;i++){
        temp.push_back(i);
        solve(k-1,n-i,temp,i+1);
        temp.pop_back();
    }

}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        solve(k,n,temp,1);
        return result;
    }
};