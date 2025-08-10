class Solution {
public:
vector<vector<int>>result;
void solve(vector<int>&arr,int target,vector<int>&temp,int sum,int i){
    //base case
    int n=arr.size();
    if(sum==target){
        result.push_back(temp);
        return ;
    }

    if(sum>target|| i>=n){
        return ;
    }

    
        if(target-sum>0){
            temp.push_back(arr[i]);
            solve(arr,target,temp,sum+arr[i],i);
            temp.pop_back();
            solve(arr,target,temp,sum,i+1);
        }
  
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum=0;
        vector<int>temp;
        solve(candidates,target,temp,sum,0);
        return result;
    }
};