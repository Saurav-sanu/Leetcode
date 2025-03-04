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


approach 2 or another way of writing

//
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        //approach 2
        int i=0;
        int j=n-1;

        //result_variabe
        int _i=0;
        int j_=n-1;
        vector<int>result(n);

        while(i<n && j>=0){
            if(nums[i]<pivot){
                result[_i]=nums[i];
                _i++;
            }
            if(nums[j]>pivot){
                result[j_]=nums[j];
                j_--;
            }
            i++;
            j--;
        }

        while(_i<=j_){
            result[_i]=pivot;
            _i++;
        }

        return result;
    }
};
