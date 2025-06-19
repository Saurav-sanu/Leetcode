class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int result=0;

        //constraints dekkhke log (base 2 1o raise paowerr 7 )+1 aaaya 24 ke brabar so loop 24 tak hi chalya hai 
        

        for(int bit=0;bit<24;bit++){
            int count=0;
            for(int &num:candidates){
                if(num&(1<<bit)){
                    count++;
                }
            }
            result=max(count,result);

        }
        return result;
    }
};