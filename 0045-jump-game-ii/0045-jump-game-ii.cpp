class Solution {
public:
    int jump(vector<int>& nums) {
        int jmp=0;
        int left=0,right=0;
        while(right<nums.size()-1){
            int farthest=0;
            for(int index=left;index<=right;index++){
                farthest=max(farthest,nums[index]+index);
            }
            left=right+1;
            right=farthest;
            jmp++;
        }
        return jmp;
    }
};