class Solution {
public:
void mergeInPlace(vector<int>&arr,int s,int e){
    int total_len=e-s+1;
    int gap=total_len/2+total_len%2;

    while(gap>0){
        int i=s;
        int j=i+gap;
        while(j<=e){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
            i++;
            j++;
        }
        gap=gap<=1?0:(gap/2)+(gap%2);
    }
}
void merge(vector<int>&arr,int s,int e){
        int mid=s+(e-s)/2;
        int leftlen=mid-s+1;
        int rightlen=e-mid;
        
        int *left=new int[leftlen];
        int *right=new int[rightlen];
        
        
        int k=s;
        for(int i=0;i<leftlen;i++){
            left[i]=arr[k];
            k++;
        }
        k=mid+1;
        for(int i=0;i<rightlen;i++){
            right[i]=arr[k];
            k++;
        }
        
        int leftindex=0;
        int rightindex=0;
        int mainarrayindex=s;
        
        
        while(leftindex<leftlen && rightindex<rightlen){
            if(left[leftindex]<right[rightindex]){
                arr[mainarrayindex]=left[leftindex];
                mainarrayindex++;
                leftindex++;
            }
            else{
                arr[mainarrayindex]=right[rightindex];
                mainarrayindex++;
                rightindex++;
            }
        }
        while(leftindex<leftlen){
            arr[mainarrayindex]=left[leftindex];
            mainarrayindex++;
            leftindex++;
            
        }
        while(rightindex<rightlen){
            arr[mainarrayindex]=right[rightindex];
            mainarrayindex++;
            rightindex++;
        }
        
        
        delete[]left;
        delete[]right;
    }
    void mergesort(vector<int>&arr,int s,int e){
        int mid=s+(e-s)/2;
        if(s>=e)return;
        mergesort(arr,s,mid);
        mergesort(arr,mid+1,e);
        mergeInPlace(arr,s,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        mergesort(nums,s,e);
        return nums;
    }
};