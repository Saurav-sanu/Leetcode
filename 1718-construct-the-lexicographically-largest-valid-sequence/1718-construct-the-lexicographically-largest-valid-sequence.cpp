class Solution {
public:
bool solve(int n,vector<int>&result,vector<bool>&used,int i){
    //bsae case
    if(i==result.size()){
        return true;
    }

    if(result[i]!=-1){
        return solve(n,result,used,i+1);
    }

    for(int num=n;num>=1;num--){
        if(used[num]){
            continue;
        }
        used[num]=true;
        result[i]=num;
        if(num==1){
            if(solve(n,result,used,i+1)==true){
                return true;
            }
            
        }
        else{
            int j=i+result[i];
            if(j<result.size() &&result[j]==-1){
                result[j]=num;
                if(solve(n,result,used,i+1)==true){
                    return true;
                }
                result[j]=-1;
            }
        }
        used[num]=false;
        result[i]=-1;
    }
    return false;

}
    vector<int> constructDistancedSequence(int n) {
        vector<int>result(2*n-1,-1);
        vector<bool>used(n+1,false);
        solve(n,result,used,0);
        return result;
    }
};