class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        //using binary search approach
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int m=nums1.size();
        int n=nums2.size();

        int l=0;
        int r=m;
        while(l<=r){
            int mid=l+(r-l)/2;

            int px=mid;
            int py=(m+n+1)/2-px;

            //left half 
            int x1= px==0?INT_MIN:nums1[px-1];
            int x2= py==0?INT_MIN:nums2[py-1];

            //right half
            int x3= px==m?INT_MAX:nums1[px];
            int x4= py==n?INT_MAX:nums2[py];

            if(x1<=x4 && x2<=x3){
                if((m+n)%2==1){
                    return max(x1,x2);
                }
                else{
                    return (max(x1,x2)+min(x3,x4))/2.0;
                }
            }
            else if(x1>x4){
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return -1;
    }
};