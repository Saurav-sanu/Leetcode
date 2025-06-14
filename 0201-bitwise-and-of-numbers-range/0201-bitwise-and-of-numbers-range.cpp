class Solution {
public:
//approach 1
    int rangeBitwiseAnd(int left, int right) {
        int shiftcount=0;
        while(left!=right){
            left=(left>>1);
            right=(right>>1);
            shiftcount++;
        }
        return (left<<shiftcount);
    }
};



class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        //approach 2

        while(right>left){
            right=(right&(right-1));
        }
        return right;
    }
};
