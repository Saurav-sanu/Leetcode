class Solution {
public:
vector<int>leftmaxarray(vector<int>&height,int n){
    vector<int>leftMax(n);

    leftMax[0]=height[0];
    for(int i=1;i<n;i++){
        leftMax[i]=max(leftMax[i-1],height[i]);
    }
    return leftMax;
}
vector<int>rightmaxarray(vector<int>&height,int n){
    vector<int>rightMax(n);

    rightMax[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--){
        rightMax[i]=max(rightMax[i+1],height[i]);
    }
    return rightMax;
}
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftmax=leftmaxarray(height,n);
        vector<int>rightmax=rightmaxarray(height,n);

        int area=0;
        for(int i=0;i<n;i++){
            int h=min(leftmax[i],rightmax[i])-height[i];
            area+=h;
        }
        return area;
    }
};