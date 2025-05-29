class Solution {
public:
void solve(vector<int>&cookies,int idx,vector<int>&children,int &result,int k){
    //base cse
    
    if(idx==cookies.size()){
        int unfairness=*max_element(children.begin(),children.end());
        result=min(result,unfairness);
        return;
    }

    int cookie=cookies[idx];
    for(int i=0;i<k;i++){
        children[i]+=cookie;
        solve(cookies,idx+1,children,result,k);

        children[i]-=cookie;
    }

    
}
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>children(k,0);
        int result=INT_MAX;
        solve(cookies,0,children,result,k);
        return result;

    }
};