class Solution {
public:
int find(int a){
    int count=0;
    while(a){
        if((a&1)==1){
            count++;
        }
        a>>=1;
    }
    return count;
}
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda=[&](int &a,int &b){
            int count_a_bit=find(a);
            int count_b_bit=find(b);

            if(count_a_bit==count_b_bit){
                return a<b;
            }
            return count_a_bit<count_b_bit;
        };
        sort(arr.begin(),arr.end(),lambda);
        return arr;
    }
};