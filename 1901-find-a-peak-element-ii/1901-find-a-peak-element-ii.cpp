class Solution {
public:
int rownumber(vector<vector<int>>& mat,int mid,int rn, int cn){
    int maxrow = 0;
    int maxval = mat[0][cn];
    for (int i = 1; i < rn; i++) {
        if (mat[i][cn] > maxval) {
            maxval = mat[i][cn];
            maxrow = i;
        }
    }
    return maxrow;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        int n=row*col;


        int s=0;
        int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int rn=mid/col;
            int cn=mid%col;

            int rowmax=rownumber(mat,mid,row,cn);
           int left = (cn-1 >= 0) ? mat[rowmax][cn-1] : -1;
            int right = (cn+1 < col) ? mat[rowmax][cn+1] : -1;

            int currnumber=mat[rowmax][cn];

            if(currnumber>left && currnumber>right){
                return {rowmax,cn};
            }

            else if(currnumber<right){
                s=mid+1;
            }
            else{
                e=mid-1;
            }

        }
        return {-1,-1};
    }
};