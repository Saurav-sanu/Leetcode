class Solution {
public:
int MOD=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int evencount=1;
        int oddcount=0;
        int count=0;

        int n=arr.size();
        int sum=0;

        for(int i=0;i<n;i++){//odd+even=odd
            sum+=arr[i];
            if(sum[i]%2==0){
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
