class Solution {
public:

    void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {
        vector<int>merged;
        int i=0;
      int j=0;
      while(i<n && j<m){
          if(arr1[i]<arr2[j]){
              merged.push_back(arr1[i]);
              i++;
          }
          else{
              merged.push_back(arr2[j]);
              j++;
          }
      }
      while(i<n){
          merged.push_back(arr1[i]);
          i++;
      }
      while(j<m){
          merged.push_back(arr2[j]);
          j++;
      }

      for (int k = 0; k < n + m; ++k) {
            arr1[k] = merged[k];
        }
    }
};