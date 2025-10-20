class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int n=row*col;

        int s=0;
        int e=n-1;

        while(s<=e){
            int mid=s+(e-s)/2;
            int currRow=mid/col;
            int currCol=mid%col;

            if(matrix[currRow][currCol]==target){
                return true;
            }
            else if(matrix[currRow][currCol]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return false;
    }
};