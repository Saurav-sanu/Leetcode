class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int countless=0;
        int equal=0;

        for(int &num:nums){
            if(num==pivot){
                equal++;
            }
            else if(num<pivot){
                countless++;
            }
        }

        int j=countless;
        int k=countless+equal;
        int i=0;

        vector<int>result(n);

        for(int &num:nums){
            if(num<pivot){
                result[i]=num;
                i++;
            }
            else if(num==pivot){
                result[j]=num;
                j++;
            }
            else{
                result[k]=num;
                k++;
            }
        }
        return result;
    }
};