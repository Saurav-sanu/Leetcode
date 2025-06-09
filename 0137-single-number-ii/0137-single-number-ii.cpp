class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(int k=0;k<=31;k++){
            int temp=(1<<k);
            int countzero=0;
            int countone=0;
            for(int &num:nums){
                if((num&temp)==0){
                    countzero++;
                }
                else{
                    countone++;
                }
            }

            if(countone%3==1){
                result|=temp;
            }
        }
        return result;
    }

};