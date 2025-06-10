class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        for(int i=0;i<32;i++){
            if((1&(n>>i))==1){
                count++;
            }

        }
        return count;
    }
};