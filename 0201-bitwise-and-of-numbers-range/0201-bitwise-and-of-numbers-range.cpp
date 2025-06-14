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