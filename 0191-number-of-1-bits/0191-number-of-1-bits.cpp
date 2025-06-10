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

//approach 2

class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n>0){
            n=n&n-1;
            count++;
        }
        return count;
    }
};


//apprach 3
class Solution {
public:
    int hammingWeight(int n) {
        int count=0;

        //approcah 3
        while(n!=0){
            count+=n%2;
            n=n/2;
        }
        return count;
    }
};


//aprahc 4
using __builtin_popcount

just return __builtin_popcount(n);
