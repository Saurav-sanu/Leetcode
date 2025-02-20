class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& interval) {
        int count=0;
        sort(interval.begin(),interval.end());
        int i=0;
        int j=1;
        int n=interval.size();
        while(j<n){
            int cs=interval[i][0];
            int ce=interval[i][1];

            int ns=interval[j][0];
            int ne=interval[j][1];

            //overlapping
            if(ns>=ce){
                i=j;

                j++;
            }
            else if(ce<=ne){
                j++;
                count++;
            }
            else if(ce>ne){
                i=j;
                j++;
                count++;

            }
        }
        return count;
    }
};