class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        int s=0;
        int e=n-1;
      
        while(s<=e){
            int maxRow=0;
            int midCol=s+(e-s)/2;
            for(int row=0;row<m;row++){
                if(mat[row][midCol]>mat[maxRow][midCol]){
                    maxRow=row;
                }
            }
            int currElement=mat[maxRow][midCol];
            int leftElement=midCol==0?-1:mat[maxRow][midCol-1];
            int rightElement=midCol==n-1?-1:mat[maxRow][midCol+1];

            if(currElement>leftElement && currElement>rightElement){
                return {maxRow,midCol};
            }
            else if(currElement<leftElement){
                e=midCol-1;
            }
            else{
                s=midCol+1;
            }

            

        }
        return {-1,-1};

    }
};