class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        //using 2 pointer
        int i=0;
        int j=0;
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>result;
        
        while(i<n && j<m){
            if(nums1[i][0]<nums2[j][0]){
                result.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i][0]>nums2[j][0]){
                result.push_back(nums2[j]);
                j++;
                
            }
            else{
                result.push_back({nums1[i][0],nums1[i][1]+nums2[j][1]});
                i++;
                j++;
            }
        }
        while(i<n){
            result.push_back(nums1[i]);
            i++;
        }
        while(j<m){
            result.push_back(nums2[j]);
            j++;

        }

        return result;
        
    }
};