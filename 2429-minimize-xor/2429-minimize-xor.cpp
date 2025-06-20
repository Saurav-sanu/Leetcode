class Solution {
public:
bool isSet(int &x,int bit){
    return x & (1 << bit);
}
void setBit(int &x,int bit){
    x|=(1<<bit);
}
void unsetBit(int &x,int bit){
    x&=~(1<<bit);
}
bool isunset(int &x,int bit){
    return (x & (1 << bit)) == 0;
}

    int minimizeXor(int num1, int num2) {
        int x=0;
        int requiredsetbit=__builtin_popcount(num2);

        for(int bit=31;bit>=0&& requiredsetbit>0 ;bit--){
            if(isSet(num1,bit)){
                setBit(x,bit);
                requiredsetbit--;
            }
        }

        for(int bit=0;bit<32&& requiredsetbit>0 ;bit++){
            if(isunset(num1,bit)){
                setBit(x,bit);
                requiredsetbit--;
            }
        }

        return x;

    }
};