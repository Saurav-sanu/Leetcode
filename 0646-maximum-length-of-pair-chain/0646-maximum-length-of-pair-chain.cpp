class Solution {
public:
int solveLIS(int prevIndex,int index,vector<vector<int>>&nums){
    //base case
    if(index>=nums.size()){
        return 0;
    }
    int take=0;
    if(prevIndex==-1 || nums[prevIndex][1]<nums[index][0]){
        take=1+solveLIS(index,index+1,nums);
    }
    int skip=solveLIS(prevIndex,index+1,nums);

    return max(skip,take);
}
    int findLongestChain(vector<vector<int>>& pairs) {
        // auto comparator =[&](vector<int>&a,vector<int>&b){
        //     return a<b;
        // };
        sort(pairs.begin(),pairs.end());

        return solveLIS(-1,0,pairs);


    }
};