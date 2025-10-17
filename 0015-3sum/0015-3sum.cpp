class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>result;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(i!=0 && arr[i]==arr[i-1]){
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k){

                if((arr[i]+arr[j]+arr[k])<0){
                    j++;
                    
                }
                else if((arr[i]+arr[j]+arr[k])>0){
                    k--;

                }
                else{
                    vector<int>temp={arr[i],arr[j],arr[k]};
                    
                    result.push_back(temp);
                    j++;
                    k--;
                    while(j<k && arr[j]==arr[j-1])j++;
                    while(j<k && arr[k]==arr[k+1])k--;
                }
            }

        }
        return result;

    }
};