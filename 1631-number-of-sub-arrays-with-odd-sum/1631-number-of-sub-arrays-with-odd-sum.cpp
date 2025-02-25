class Solution {
public:
int MOD=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int evencount=1;
        int oddcount=0;
        int count=0;

        int n=arr.size();
        vector<int>prefSum(n,0);
        prefSum[0]=arr[0];

        for(int i=1;i<n;i++){
            prefSum[i]=arr[i]+prefSum[i-1];
        }

        for(int i=0;i<n;i++){
            if(prefSum[i]%2==0){//odd+even=odd
                count=(count+oddcount)%MOD;
                evencount++;
            }
            else{//even+odd=odd
                count=(count+evencount)%MOD;
                oddcount++;
            }
        }
        return count;
    }
};