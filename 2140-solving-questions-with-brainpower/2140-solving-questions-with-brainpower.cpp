class Solution {
public:
long long solve(vector<vector<int>>& questions,int index,vector<int>&t){
    //base case
    if(index>=questions.size()){
        return 0;
    }
    if(t[index]!=-1){
        return t[index];
    }

    long long take=questions[index][0]+solve(questions,index+questions[index][1]+1,t);
    long long skip=solve(questions,index+1,t);

    return t[index]=max(take,skip);
}
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<int>t(n+1,-1);
        if(n==1){
            return questions[0][0];
        }

        return solve(questions,0,t);
    }
};