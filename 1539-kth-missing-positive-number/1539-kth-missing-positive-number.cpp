class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num=1;
        int i=0;
        int n=arr.size();

        while(i<n && k>0){
            if(num!=arr[i]){
                k--;
            }
            else{
                i++;
            }

            num++;
        }
        while(k--){
            num++;
        }
        return num-1;
    }
};