class Solution {
public:
void solve(int n,int k,string &curr,string &result,int &count){
    //base ase
    if(curr.length()==n){
        count++;
        if(count==k){
            result=curr;
        }
        return ;


    }

    for(char ch='a';ch<='c';ch++){
        if(!curr.empty() && ch==curr.back()){
            continue;
        }

        curr.push_back(ch);

        solve(n,k,curr,result,count);
        curr.pop_back();
    }
    
}
    string getHappyString(int n, int k) {
        string result="";
        string curr="";
        int count=0;
        solve(n,k,curr,result,count);
        return result;
    }
};