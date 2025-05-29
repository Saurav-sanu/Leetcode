class Solution {
public:
    void solve(vector<vector<int>>& requests,vector<int>&resultant,int count,int idx,int &result){
        //base case
        if(idx==requests.size()){
            bool allzero=true;
            for(auto &x:resultant){
                if(x!=0){
                    allzero=false;
                    break;
                }
            }
            if(allzero==true){
                result=max(result,count);

            }
            return ;
        }


        int from=requests[idx][0];
        int to=requests[idx][1];

        resultant[from]--;
        resultant[to]++;

        solve(requests,resultant,count+1,idx+1,result);

        resultant[from]++;
        resultant[to]--;

        solve(requests,resultant,count,idx+1,result);

        
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        int count=0;
        int result=INT_MIN;
        vector<int>resultant(n,0);
        solve(requests,resultant,count,0,result);
        return result;
    }

};