class Solution {
public:
void addone(string &s){
    int i=s.length()-1;
    while(i>=0 && s[i]!='0'){
        s[i]='0';
        i--;
    }

    if(i<0){
        s='1'+s;
    }
    else{
        s[i]='1';

    }
}
    int numSteps(string s) {
        int op=0;

        while(s.length()>1){
            int n=s.length();
            if(s[n-1]=='0'){
                // remove
                s.pop_back();
            }
            else{
                addone(s);
            }
            op++;

        }
        return op;
    }
};


class Solution {
public:
    int numSteps(string s) {
        //approach 2
        int op=0;
        int n=s.length();
        int carry=0;
        for(int i=n-1;i>=1;i--){
            if(((s[i]-'0')+carry)%2==1){//odd
                op+=2;
                carry=1;
            }
            else{
                op++;
            }
        }
        return op+carry;
    }
};
